#include <stdio.h>


int findGroupSize(int S, int D) {
    int daysPassed = 0;  // 經過的總天數
    int currentGroupSize = S;  // 當前旅行團的人數

    // 持續增加天數直到達到或超過指定的天數D
    while(daysPassed < D) {
        daysPassed += currentGroupSize;  // 增加當前旅行團的停留天數
        if(daysPassed < D) {
            currentGroupSize++;  // 如果還沒到達第D天，下一團旅行團的人數會加一
        }
    }

    return currentGroupSize;  // 返回在第D天入住的旅行團的人數
}

int main() {
    int S, D;

    // 使用者輸入

    scanf("%d %d", &S, &D);

    // 計算並輸出結果
    printf("%d\n", findGroupSize(S, D));

    return 0;
}
