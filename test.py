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
        command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )
    return result.stdout, result.stderr, result.returncode


def delete_file(file_path: str):
    """
    刪除指定的檔案。

    Args:
        file_path (str): 欲刪除的檔案路徑。

    Returns:
        None

    Raises:
        None
    """
    if os.path.exists(file_path):
        os.remove(file_path)


# 主函數
def main():
    # 編譯 funtional_test.c
    functional_test_output = "funtional_test"
    compile_functional_test_command = (
        f"{C_COMPILER} funtional_test.c {FLAGS} {functional_test_output}.out"
    )
    stdout, stderr, returncode = run_command(compile_functional_test_command)
    if returncode != 0:
        print("functional_test.c 編譯失敗")
        return

    # 開始處理 test
    print(f"開始處理 {test} ...")

    # 初始化 test_result 表頭
    test_result: list[list] = [
        ["學號", "平均錯誤", "功能適當性", "執行時間", "記憶體使用量"]
    ]

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
            errors_num: int = 0
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
                continue

            # 執行編譯命令
            print(f"開始編譯 {c_cpp_file} ...")
            stdout, stderr, returncode = run_command(compile_command)
            # 編譯失敗
            if returncode != 0:
                test_result.append([file_base_name, None, None, None, None])
                print(f"{c_cpp_file} 編譯失敗")
            else:

                # 計算可讀性
                lines_command = f"wc -l < {c_cpp_file}"
                stdout, stderr, returncode = run_command(lines_command)
                lines = int(stdout.decode("utf-8").strip()) + 1
                cpplint_command = f"cpplint --filter='-legal/copyright' {c_cpp_file} 2>/dev/null | tail -n 1"
                stdout, stderr, returncode = run_command(cpplint_command)
                if stdout.decode("utf-8").strip().startswith("Total errors found: "):
                    errors_num = int(stdout.decode("utf-8").strip().split(": ")[1])
                errors_num = round((errors_num / lines), 2)

                # 計算執行時間
                start_time: int = time.time_ns()
                stdout, stderr, returncode = run_command(
                    f"timeout 10s ./{output}.out < ./{test}/input.txt > {output}_derived.txt"
                )
                end_time: int = time.time_ns()
                # 執行失敗
                if returncode != 0:
                    test_result.append([file_base_name, errors_num, None, None, None])
                    print(f"{c_cpp_file} 執行失敗")
                # 執行超時
                elif returncode == 124:
                    test_result.append([file_base_name, errors_num, None, None, None])
                    print(f"{c_cpp_file} 執行超時")
                else:
                    time_taken = (end_time - start_time) // 1_000_000

                    # 功能適當性
                    # 執行 funtional_test.out
                    functional_test_command = f"./{functional_test_output}.out ./{test}/output.txt {output}_derived.txt"
                    stdout, stderr, returncode = run_command(functional_test_command)
                    if returncode != 0:
                        test_result.append(
                            [file_base_name, errors_num, None, None, None]
                        )
                        print("functional_test.c 執行失敗")
                        print(stderr.decode("utf-8"))
                    else:
                        # 讀取 功能適當性
                        functionality = float(stdout.decode("utf-8").strip())
                        # 適當性 < 15.0 時 不測試 時間 空間
                        if functionality < 15.0:
                            test_result.append(
                                [file_base_name, errors_num, functionality, None, None]
                            )
                            print(f"{c_cpp_file} 功能適當性 < 15.0")
                        else:
                            # 記憶體使用量
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

                            # 輸出正確
                            test_result.append(
                                [
                                    file_base_name,
                                    errors_num,
                                    functionality,
                                    time_taken,
                                    memory_usage,
                                ]
                            )
                            print(f"{c_cpp_file} 輸出正確")

            # 刪除不需要的檔案
            delete_file(f"{output}_derived.txt")
            delete_file(f"{output}.out")
            delete_file(massif_out_file)
            delete_file(f"{output}_analysis.txt")

    # 將 test_result 寫入 CSV 檔案
    with open(f"{test}_raw.csv", "w", newline="") as f:
        writer = csv.writer(f)
        writer.writerows(test_result)


if __name__ == "__main__":
    main()
