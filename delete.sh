#!/bin/bash

# 指定要搜索的目錄，默認為當前目錄
directory="${1:-.}"

# 查找並列出符合條件的檔案
# find "$directory" -type f -name '*_analysis.txt'
find "./test/test4" -type f -name '*_analysis.txt' -exec rm -v {} +
# 刪檔案
# find "$directory" -type f -name '*_analysis.txt' -exec rm -v {} +

# # 使用 find 命令查找符合條件的檔案並計算數量
# file_count=$(find "$directory" -type f -name '*_analysis.txt' | wc -l)

# # 輸出找到的檔案數量
# echo "找到 $file_count 個符合條件的檔案"