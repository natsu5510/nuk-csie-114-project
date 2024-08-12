#include <stdio.h>

  // 找尋第D天的團隊人數
long long findGroupSize(long long S, long long D) {
    long long currentGroupSize = S;                     // 初始團隊人數為S
    long long day = 1;                                  // 初始天數為1(因為S最小為1)

                                                        // 不斷循環迴圈直到找到第D天的團隊人數
    while (day < D) {
        currentGroupSize++;                             // 增加團隊人數
        day += currentGroupSize;                        // 按照當前團隊人數增加天數

      // 不斷循環直到day >= D，此時currentGroupSize為第D天的團隊人數
    }

    return currentGroupSize;                          
}

int main() {
    long long S, D;                                     // S和D用於輸入團隊人數和天數


    return 0;  
}