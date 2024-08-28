import pandas as pd

# 第幾次測試
TEST = "test5"

# 各項分數的滿分
FAULT_FULL_SCORE = 15
EXECUTION_TIME_FULL_SCORE = 20
MEMORY_USAGE_FULL_SCORE = 15

# 各類別的下限
A_CLASS_LOWER_BOUND = 50
B_CLASS_LOWER_BOUND = 20
C_CLASS_LOWER_BOUND = 5
D_CLASS_SCORE = 0


def strip_dataframe(df: pd.DataFrame) -> pd.DataFrame:
    """去除 DataFrame 的多餘空格"""
    df.columns = df.columns.str.strip()
    df = df.map(lambda x: x.strip() if isinstance(x, str) else x)
    return df


def read_test_csv(test: str) -> pd.DataFrame:
    # 讀 csv檔
    df = pd.read_csv(f"{test}_raw.csv")

    # 去除多餘空格 並 排序
    df = strip_dataframe(df)

    # 定義 各欄位的 數字型別
    df["fault_per_line"] = pd.to_numeric(df["fault_per_line"], errors="coerce")
    df["functional_score"] = pd.to_numeric(df["functional_score"], errors="coerce")
    df["execution_time"] = pd.to_numeric(df["execution_time"], errors="coerce")
    df["memory_usage"] = pd.to_numeric(df["memory_usage"], errors="coerce")

    return df


def add_class_column(df: pd.DataFrame) -> pd.DataFrame:
    # 將 df 一列一列的 判斷類別
    for index, row in df.iterrows():
        # 可讀性 為 空值：D class (編譯失敗)
        if pd.isnull(row["fault_per_line"]):
            df.at[index, "class"] = "D"
            continue

        # 適當性 為 空值：C class (全錯(超時))
        if pd.isnull(row["functional_score"]):
            df.at[index, "class"] = "C"
            continue

        functional_score = float(row["functional_score"])
        # 適當性 == 0.0：C class (全錯(超時))
        if functional_score == 0.0:
            df.at[index, "class"] = "C"
            continue

        # 0.0 < 適當性 < 15.0：B class (部分錯)
        if 0.0 < functional_score and functional_score < 15.0:
            df.at[index, "class"] = "B"
            continue

        # 適當性 == 15.0：A class (全對)
        if functional_score == 15.0:
            df.at[index, "class"] = "A"

    return df


def calculate_fault_score(x: float, min_value: float, max_value: float) -> float:
    return round(FAULT_FULL_SCORE * ((max_value - x) / (max_value - min_value)), 2)


def calculate_execution_time_score(x: int, min_value: int, max_value: int) -> float:
    return round(
        EXECUTION_TIME_FULL_SCORE * ((max_value - x) / (max_value - min_value)), 2
    )


def calculate_memory_usage_score(x: int, min_value: int, max_value: int) -> float:
    return round(
        MEMORY_USAGE_FULL_SCORE * ((max_value - x) / (max_value - min_value)), 2
    )


def calculate_scores(df: pd.DataFrame) -> pd.DataFrame:
    max_fault_per_line = df["fault_per_line"].max()
    min_fault_per_line = df["fault_per_line"].min()

    max_execution_time = df["execution_time"].max()
    min_execution_time = df["execution_time"].min()

    max_memory_usage = df["memory_usage"].max()
    min_memory_usage = df["memory_usage"].min()

    # 將 df 一列一列的計算分數
    for index, row in df.iterrows():
        # D class 不用計算分數
        if row["class"] == "D":
            continue

        # 初始化分數
        fault_score = pd.NA
        execution_time_score = pd.NA
        memory_usage_score = pd.NA

        # 計算 可讀性分數
        fault_per_line = row["fault_per_line"]
        fault_score = calculate_fault_score(
            fault_per_line, min_fault_per_line, max_fault_per_line
        )
        # 將分數寫入 df
        df.at[index, "fault_per_line"] = fault_score

        # A class 要計算 時間 和 空間 分數
        if row["class"] == "A":
            # 執行時間分數
            execution_time = int(row["execution_time"])
            execution_time_score = calculate_execution_time_score(
                execution_time, min_execution_time, max_execution_time
            )
            # 將分數寫入 df
            df.at[index, "execution_time"] = execution_time_score

            # 記憶體使用量分數
            memory_usage = int(row["memory_usage"])
            memory_usage_score = calculate_memory_usage_score(
                memory_usage, min_memory_usage, max_memory_usage
            )
            # 將分數寫入 df
            df.at[index, "memory_usage"] = memory_usage_score

    # 表頭改名
    df.rename(
        columns={
            "id": "ID",
            "fault_per_line": "fault",
            "functional_score": "correctness",
            "execution_time": "time",
            "memory_usage": "space",
        },
        inplace=True,
    )

    # 計算總分
    df = sum_total_scores(df)

    return df


def sum_total_scores(df: pd.DataFrame) -> pd.DataFrame:
    for index, row in df.iterrows():
        # D class (無法編譯)：0
        if row["class"] == "D":
            df.at[index, "total"] = D_CLASS_SCORE
        # C class (全錯(超時))：5 + 可讀性分數
        elif row["class"] == "C":
            df.at[index, "total"] = C_CLASS_LOWER_BOUND + row["fault"]
        # B class (部分錯)：20 + 可讀性分數 + 適當性分數
        elif row["class"] == "B":
            df.at[index, "total"] = (
                B_CLASS_LOWER_BOUND + row["fault"] + row["correctness"]
            )
        # A class (全對)：50 + 可讀性分數 + 時間分數 + 空間分數
        elif row["class"] == "A":
            df.at[index, "total"] = (
                A_CLASS_LOWER_BOUND + row["fault"] + row["time"] + row["space"]
            )
    df["total"] = df["total"].round(2)
    return df


if __name__ == "__main__":
    df = read_test_csv(TEST)
    df = add_class_column(df)
    df = calculate_scores(df)
    df.to_csv(f"{TEST}_result.csv", index=False)
