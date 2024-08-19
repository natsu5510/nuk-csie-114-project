# nuk-csie-114-project

## 環境配置

### 作業系統

- Ubuntu 22.04 或 WSL2

### 安裝套件

- gcc/g++
```bash
sudo apt install build-essential
```

- python3
```bash
sudo apt install python3 python3-pip
```

- python3-venv ( python虛擬環境 ) `可選`
```bash
sudo apt install python3-venv
```

- cpplint
```bash
sudo apt install cpplint
```

- valgrind
```bash
sudo apt install valgrind
```

## 編譯與執行

### 生成 `test#_raw.csv`

> [!NOTE]
> 更改 `test.py` 中的 `TEST` 變數，來選擇第幾次測驗

然後執行
```bash
python3 test.py
```

### 生成 `test#_result.csv`

> [!NOTE]
> 更改 `calculate_score.py` 中的 `TEST` 變數，來選擇第幾次測驗

然後執行
```bash
python3 calculate_score.py
```

### 生成 `combined_results.csv`

> [!NOTE]
> 更改 `CSV_FILES` 變數，來選擇要合併的檔案  
> 更改 `MERGE_METHOD` 變數，來選擇合併的方式

```bash
python3 combine_results.py
```
