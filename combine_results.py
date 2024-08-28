import os
import pandas as pd

# 要合併的 CSV 檔案列表
CSV_FILES = [
    "test1_result.csv",
    "test2_result.csv",
    "test3_result.csv",
    "test4_result.csv",
    "test5_result.csv",
]

# 要合併的方式 (inner, outer, left, right)
MERGE_METHOD = "outer"


def check_csv_files_exist():
    for csv_file in CSV_FILES:
        if not os.path.exists(csv_file):
            print(f"{csv_file} 不存在")
            return False
    return True


def strip_dataframe(df: pd.DataFrame) -> pd.DataFrame:
    """去除 DataFrame 的多餘空格"""
    df.columns = df.columns.str.strip()
    df = df.map(lambda x: x.strip() if isinstance(x, str) else x)
    return df


def combine_csv_files(output_file_name="combined_results.csv"):
    # 檢查所有 CSV 檔案是否存在
    if not check_csv_files_exist():
        return

    # 初始化一個空的 DataFrame
    combined_df = pd.DataFrame()

    # 逐個讀取 CSV 檔案並提取 'ID' 和 'total' 欄位
    for csv_file in CSV_FILES:
        # 讀取 CSV 檔案
        df = pd.read_csv(csv_file)

        # 去除多餘空格
        df = strip_dataframe(df)

        # 只保留 'ID' 和 'total' 欄位
        df = df[["ID", "total"]].rename(columns={"total": csv_file.split("_")[0]})

        # 將所有 CSV 檔案合併
        if combined_df.empty:
            combined_df = df
        else:
            combined_df = pd.merge(combined_df, df, on="ID", how=MERGE_METHOD)

    # 將合併後的 DataFrame 寫入新的 CSV 檔案
    combined_df.to_csv(output_file_name, index=False)


if __name__ == "__main__":
    combine_csv_files()
