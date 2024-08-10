import os
import csv
import sys

def parse_analysis_file(file_path):
    """解析分析檔案並提取所需的數據"""
    data = {
        "可讀性": None,
        "功能性": None,
        "時間(ms)": None,
        "空間(byte)": None
    }
    
    with open(file_path, 'r') as file:
        for line in file:
            if '可讀性' in line:
                data["可讀性"] = float(line.split('：')[1].strip())
            elif '功能性' in line:
                data["功能性"] = float(line.split('：')[1].strip())
            elif '時間(ms)' in line:
                data["時間(ms)"] = int(line.split('：')[1].strip().replace('ms', ''))
            elif '空間(byte)' in line:
                data["空間(byte)"] = int(line.split('：')[1].strip())
    
    return data

def main():
    # 設置要處理的目錄
    current_directory = os.getcwd()
    # print(args[1])
    
    # 結果將寫入的 CSV 檔案
    csv_file_path = os.path.join(current_directory, sys.argv[1]+'_results.csv')
    
    # 打開 CSV 檔案進行寫入
    with open(csv_file_path, 'w', newline='', encoding='utf-8') as csvfile:
        csv_writer = csv.writer(csvfile)
        # 寫入 CSV 標題
        csv_writer.writerow(['學號', '可讀性', '功能性', '時間', '空間'])
        
        # 遍歷當前目錄中的所有資料夾
        test = os.path.join(current_directory, 'test', sys.argv[1])
        for folder in os.listdir(test):
            folder_path = os.path.join(test, folder)
            if os.path.isdir(folder_path):
                for file_suffix in ['_analysis.txt', '_ai_analysis.txt']:
                    analysis_file_path = os.path.join(folder_path, f'{folder}{file_suffix}')
                    
                    if os.path.isfile(analysis_file_path):
                        # 解析檔案
                        data = parse_analysis_file(analysis_file_path)
                        
                        # 取得學號，根據檔案後綴進行調整
                        student_id = f'{folder}_ai' if '_ai' in file_suffix else folder
                        # 寫入 CSV 檔案
                        csv_writer.writerow([
                            student_id,
                            data["可讀性"],
                            data["功能性"],
                            data["時間(ms)"],
                            data["空間(byte)"]
                        ])
    
    print(f'CSV 檔案已成功寫入: {csv_file_path}')

if __name__ == "__main__":
    main()
