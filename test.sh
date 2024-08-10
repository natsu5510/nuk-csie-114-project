#!/bin/bash

# 設置編譯器和選項
C_COMPILER="gcc"
CPP_COMPILER="g++"
FLAGS="-o"

# tests=("test1" "test2" "test3" "test4" "test5")
tests=("test4")
for test in "${tests[@]}"; do
    echo "處理 $test"
    students=$(find ./test/$test -mindepth 1 -maxdepth 1 -type d)

    for student in $students; do
        # 在根目錄下查找所有 C 源碼文件
        find "$student" -type f \( -name "*.c" -o -name "*.cpp" \) | while read -r file; do
            # 提取文件名（不包括路徑和擴展名）
            filename=$(basename "$file")
            base_name="${filename%.*}"
            # 提取文件擴展名
            extension="${filename##*.}"
            # 提取目錄名（不包括文件名）
            dirname=$(dirname "$file")
            # 設置輸出文件的路徑
            output="$dirname/$base_name"
            
            if [ "$extension" == "c" ]; then
                echo "編譯 C 源碼文件 $file ..."
                $C_COMPILER "$file" $FLAGS "$output.out"
            elif [ "$extension" == "cpp" ]; then
                echo "編譯 C++ 源碼文件 $file ..."
                $CPP_COMPILER "$file" $FLAGS "$output.out"
            fi
            
            if [ $? -eq 0 ]; then
                echo "$file 編譯成功，生成了 $output"

                # 可讀性分析
                errors=$(cpplint --filter="-legal/copyright" $file 2>/dev/null | tail -n 1 | grep -o '[0-9]\+')
                let lines=$(wc -l < $file)+1
                printf "可讀性：%.2f\n" $(echo "(1/($errors/$lines))*0.75" | bc -l) >> ${output}_analysis.txt

                # 計算執行時間(time limit: 10s)
                ts=$(date +%s%N)
                timeout 10s ./$output.out < ./test/$test/input.txt > ${output}"_derived.txt"

                if [ $? -eq 124 ]; then
                    # 超時
                    echo 超時
                else
                    # 未超時
                    tt=$((($(date +%s%N) - $ts)/1000000))
                    echo "時間(ms)：${tt}ms" >> ${output}_analysis.txt
                    # 使用valgrind的massif工具測量heap、stack區段記憶體使用狀況，指定輸出文件名為massif.out.memory_usage，捨棄螢幕輸出
                    (valgrind --tool=massif --stacks=yes --massif-out-file=$dirname/massif.out.$base_name $output.out < ./test/$test/input.txt > /dev/null) 2> /dev/null
                    # 利用grep、awk找出massif.out.memory_usage中heap+stack的最大值，並存到變數peak
                    peak=$(grep -E 'snapshot=|mem_heap_B=|mem_heap_extra_B=|mem_stacks_B=' $dirname/massif.out.$base_name |\
                    awk -F "=" '(NR-1)%4!=0{print $2}' | awk '{sum+=$1} NR%3==0 {print sum; sum=0}' | sort -g | tail -n 1)

                    echo -ne "空間(byte)：" >> ${output}_analysis.txt
                    # size指令取得text、data、bss區段記憶體用量，再利用awk分輸出text區段、(data+bss+heap+stack)區段的記憶體用量
                    # size ./$output.out | awk -v peak=$peak -F " " 'NR==2{print "text = "$1 " Bytes\nmemory = "$2+$3+peak " Bytes"}' >> ${output}_analysis.txt
                    size ./$output.out | awk -v peak=$peak -F " " 'NR==2{print $1+$2+$3+peak}' >> ${output}_analysis.txt
                fi

                # 功能適用性
                ./a.out ./test/$test/output.txt ${output}"_derived.txt" >> ${output}_analysis.txt
            else
                echo "$file 編譯失敗"
            fi
        done
    done
    python3 record.py $test
done