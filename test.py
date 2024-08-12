import csv
import os
import subprocess
import time
import glob

# 定義 C 和 C++ 編譯器
C_COMPILER = "gcc"
CPP_COMPILER = "g++"
FLAGS = "-o"
test = "test4"


# 執行終端機命令的函數
def run_command(command: str) -> tuple[str, str, int]:
    """
    執行指令並回傳結果。

    Args:
        command (str): 要執行的指令。

    Returns:
        tuple: 包含三個元素的元組，依序為 stdout、stderr 和 returncode。
            - stdout (str): 指令執行後的標準輸出。
            - stderr (str): 指令執行後的錯誤輸出。
            - returncode (int): 指令執行後的返回碼。
    """
    result = subprocess.run(
        command, shell=True, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )
    return result.stdout, result.stderr, result.returncode


# 主函數
def main():
    # 編譯 funtional_test.c
    functional_test_output = "funtional_test.out"
    compile_functional_test_command = (
        f"{C_COMPILER} funtional_test.c {FLAGS} {functional_test_output}"
    )
    stdout, stderr, returncode = run_command(compile_functional_test_command)
    if returncode != 0:
        print("functional_test.c 編譯失敗")
        return

    # 開始處理 test
    print(f"開始處理 {test} ...")
    # 獲取 test 下所有 學生目錄(stu_dir)
    students = [
        stu_dir for stu_dir in glob.glob(f"./{test}/*") if os.path.isdir(stu_dir)
    ]

    for student in students:
        # 獲取所有 .c/.cpp 檔
        for c_cpp_file in glob.glob(f"{student}/**/*.[cC]", recursive=True) + glob.glob(
            f"{student}/**/*.[cC][pP][pP]", recursive=True
        ):

            # 初始化 程式碼評估分數
            readability: float = None
            functionality: float = None
            time_taken: int = None
            memory_usage: int = None

            # 取得檔名："a1125501.cpp"
            file_name = os.path.basename(c_cpp_file)
            # 取得檔名(不含副檔名)："a1125501"
            file_base_name = os.path.splitext(file_name)[0]
            # 取得檔名的副檔名：".cpp"
            file_extension = os.path.splitext(file_name)[1]
            # 取得檔案所在的目錄："./test4/a1125501"
            file_dir_name = os.path.dirname(c_cpp_file)
            # 欲輸出檔案路徑 + 檔名(不含副檔名)："./test4/a1125501/a1125501"
            output = os.path.join(file_dir_name, file_base_name)

            # gcc/g++ 編譯命令
            if file_extension in [".c", ".C"]:
                compile_command = f"{C_COMPILER} {c_cpp_file} {FLAGS} {output}.out"
            elif file_extension in [".cpp", ".CPP", ".cxx", ".CXX"]:
                compile_command = f"{CPP_COMPILER} {c_cpp_file} {FLAGS} {output}.out"
            else:
                print(f"{c_cpp_file} 不是 C 或 C++ 檔案")
                continue

            # 執行編譯命令
            stdout, stderr, returncode = run_command(compile_command)
            if returncode != 0:
                print(f"{c_cpp_file} 編譯失敗")
                continue

            # 計算可讀性
            lines_command = f"wc -l < {c_cpp_file}"
            stdout, stderr, returncode = run_command(lines_command)
            lines = int(stdout.strip()) + 1

            cpplint_command = f"cpplint --filter='-legal/copyright' {c_cpp_file} 2>/dev/null | tail -n 1 | grep -o '[0-9]\+'"
            stdout, stderr, returncode = run_command(cpplint_command)
            errors = int(stdout.strip())

            readability = round((1 / (errors / lines)) * 0.75, 2)

            # 計算執行時間
            start_time: int = time.time_ns()
            stdout, stderr, returncode = run_command(
                f"timeout 10s ./{output}.out < ./{test}/input.txt > {output}_derived.txt"
            )
            if returncode == 124:
                print(f"{c_cpp_file} 執行超時")
            else:
                time_taken = (time.time_ns() - start_time) // 1000000

            # 使用 valgrind 測量記憶體使用狀況
            massif_out_file = os.path.join(
                file_dir_name, f"massif.out.{file_base_name}"
            )
            run_command(
                f"valgrind --tool=massif --stacks=yes --massif-out-file={massif_out_file} {output}.out < ./{test}/input.txt > /dev/null 2> /dev/null"
            )

            # 解析 massif 輸出
            peak: int = 0
            with open(massif_out_file, "r") as f:
                for line in f:
                    if (
                        "mem_heap_B=" in line
                        or "mem_heap_extra_B=" in line
                        or "mem_stacks_B=" in line
                    ):
                        peak += int(line.split("=")[1])

            memory_usage = peak

            # 功能適用性
            # 執行 funtional_test.out
            functional_test_command = f"./{functional_test_output} ./{test}/input.txt"
            stdout, stderr, returncode = run_command(functional_test_command)
            if returncode != 0:
                print("functional_test.c 執行失敗")
            else:
                # 根據 stdout 或其他標準計算功能適用性分數
                functionality = 15.0  # 假設功能性為 15.0，這裡需要根據實際情況計算

            # 將 student_results 寫入 CSV 檔案
            student_results: list[str, float, float, int, int] = [
                file_base_name,
                readability,
                functionality,
                time_taken,
                memory_usage,
            ]
            student_csv_path = f"{output}.csv"
            with open(student_csv_path, mode="w", newline="") as file:
                writer = csv.writer(file)
                writer.writerow(student_results)

            # # 刪除 analysis.txt 檔
            # if os.path.exists(f"{output}_analysis.txt"):
            #     os.remove(f"{output}_analysis.txt")
            # # 刪除 derived.txt 檔
            # if os.path.exists(f"{output}_derived.txt"):
            #     os.remove(f"{output}_derived.txt")
            # # 刪除 csv 檔
            # if os.path.exists(student_csv_path):
            #     os.remove(student_csv_path)
            # # 刪除 massif.out 檔
            # if os.path.exists(massif_out_file):
            #     os.remove(massif_out_file)
            # # 刪除 .out 檔
            # if os.path.exists(f"{output}.out"):
            #     os.remove(f"{output}.out")


if __name__ == "__main__":
    main()
