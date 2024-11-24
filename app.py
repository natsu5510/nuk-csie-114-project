from flask import Flask, render_template, request, jsonify
import random  # 模擬計算結果用，實際計算程式需自行替換
from test import run_command
import os
import time

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/submit", methods=["POST"])
def submit():
    code = request.form.get("code")
    language = request.form.get("language")

    # 根據選擇的語言決定檔案名稱
    if language == "C":
        c_cpp_file = "user_code.c"
    elif language == "C++":
        c_cpp_file = "user_code.cpp"

    # 將程式碼存入檔案
    if c_cpp_file:
        with open(c_cpp_file, "w") as file:
            file.write(code)

    # 定義 C 和 C++ 編譯器
    C_COMPILER = "gcc"
    CPP_COMPILER = "g++"
    FLAGS = "-o"
    test = "test5"

    # 初始化 程式碼評估分數
    errors_num: int = 0
    functionality: float = None
    time_taken: int = None
    memory_usage: int = None

    result = {
        "compile_info": None,
        "accuracy": None,
        "execution_time": None,
        "memory_usage": None,
        "error_per_line": None
    }

    # 取得檔名："a1125501.cpp"
    file_name = os.path.basename(c_cpp_file)
    # 取得檔名(不含副檔名)："a1125501"
    file_base_name = os.path.splitext(file_name)[0]
    # 取得檔名的副檔名：".cpp"
    file_extension = os.path.splitext(file_name)[1]
    # 取得檔案所在的目錄："./test4/a1125501"
    file_dir = os.path.dirname(c_cpp_file)
    # 欲輸出檔案路徑 + 檔名(不含副檔名)："./test4/a1125501/a1125501"
    output = os.path.join(file_dir, file_base_name)
    # massif.out 輸出檔案路徑："./test4/a1125501/massif.out.a1125501"
    massif_out_file = os.path.join(file_dir, f"massif.out.{file_base_name}")

    # gcc/g++ 編譯命令
    if file_extension in [".c", ".C"]:
        compile_command = f"{C_COMPILER} {c_cpp_file} {FLAGS} {output}.out"
    elif file_extension in [".cpp", ".CPP", ".cxx", ".CXX"]:
        compile_command = f"{CPP_COMPILER} {c_cpp_file} {FLAGS} {output}.out"
    else:
        print(f"{c_cpp_file} 不是 C 或 C++ 檔案")
    # 執行編譯命令
    print(f"開始編譯 {c_cpp_file} ...")
    stdout, stderr, returncode = run_command(compile_command)
    
    # 編譯失敗
    if returncode != 0:
        result["compile_info"] = "編譯失敗"
        # test_result.append([file_base_name, None, None, None, None])
        # print(f"{c_cpp_file} 編譯失敗")
    else:
        result["compile_info"] = "編譯成功"
        # 計算可讀性
        lines_command = f"wc -l < {c_cpp_file}"
        stdout, stderr, returncode = run_command(lines_command)
        lines = int(stdout.decode("utf-8").strip()) + 1
        cpplint_command = f"cpplint --filter='-legal/copyright' {c_cpp_file} 2>/dev/null | tail -n 1"
        stdout, stderr, returncode = run_command(cpplint_command)
        if stdout.decode("utf-8").strip().startswith("Total errors found: "):
            errors_num = int(stdout.decode("utf-8").strip().split(": ")[1])
        errors_num = round((errors_num / lines), 2)
        result["error_per_line"] = errors_num

        # 計算執行時間
        start_time: int = time.time_ns()
        stdout, stderr, returncode = run_command(
            f"timeout 10s ./{output}.out < ./{test}/input.txt > {output}_derived.txt"
        )
        end_time: int = time.time_ns()
        # 執行失敗
        if returncode != 0:
            result["execution_time"] = "執行失敗"
            # test_result.append([file_base_name, errors_num, None, None, None])
            print(f"{c_cpp_file} 執行失敗")
        # 執行超時
        elif returncode == 124:
            result["execution_time"] = "超時"
            # test_result.append([file_base_name, errors_num, None, None, None])
            print(f"{c_cpp_file} 執行超時")
        else:
            time_taken = (end_time - start_time) // 1_000_000
            result["execution_time"] = time_taken

            # 功能適當性
            # 執行 funtional_test.out
            functional_test_command = f"./funtional_test.out ./{test}/output.txt {output}_derived.txt"
            stdout, stderr, returncode = run_command(functional_test_command)
            if returncode != 0:
                result["execution_time"] = time_taken
                # test_result.append(
                #     [file_base_name, errors_num, None, None, None]
                # )
                print("functional_test.c 執行失敗")
                print(stderr.decode("utf-8"))
            else:
                # 讀取 功能適當性
                functionality = float(stdout.decode("utf-8").strip())
                result["accuracy"] = functionality
                # 適當性 < 15.0 時 不測試 時間 空間
                if functionality < 15.0:
                    # test_result.append(
                    #     [file_base_name, errors_num, functionality, None, None]
                    # )
                    print(f"{c_cpp_file} 功能適當性 < 15.0")
                else:
                    # 記憶體使用量
                    run_command(
                        f"valgrind --tool=massif --stacks=yes --massif-out-file={massif_out_file} {output}.out < ./{test}/input.txt > /dev/null 2> /dev/null"
                    )
                    # 解析 massif 輸出
                    lines = list()
                    with open(massif_out_file, "r") as f:
                        for line in f:
                            if (
                                "snapshot=" in line
                                or "mem_heap_B=" in line
                                or "mem_heap_extra_B=" in line
                                or "mem_stacks_B=" in line
                            ):
                                lines.append(int(line.split("=")[1]))

                    snapshots = list()
                    for i in range(0, len(lines), 4):
                        snapshots.append(sum(lines[i + 1 : i + 4]))

                    peak = max(snapshots)

                    stdout, stderr, returncode = run_command(
                        f"size ./{output}.out"
                    )

                    lines = stdout.splitlines()
                    parts = lines[1].split()
                    total = sum(int(part) for part in parts[:3])
                    memory_usage = peak + total
                    result["memory_usage"] = memory_usage

                    # 輸出正確
                    # test_result.append(
                    #     [
                    #         file_base_name,
                    #         errors_num,
                    #         functionality,
                    #         time_taken,
                    #         memory_usage,
                    #     ]
                    # )
                    print(f"{c_cpp_file} 輸出正確")

    # 刪除不需要的檔案
    # delete_file(f"{output}_derived.txt")
    # delete_file(f"{output}.out")
    # delete_file(massif_out_file)
    # delete_file(f"{output}_analysis.txt")

    return jsonify(result)

if __name__ == "__main__":
    app.run(debug=True)
