#include <stdio.h>
#pragma warning(disable:4996)

int main() {
    int S; // 第一組旅行團人數
    long long D; // 要查找的入住天數

    while (scanf("%d %lld", &S, &D) == 2) {
        long long currentDay = 1; // 當前天數
        long long currentGroupSize = S; // 當前旅行團人數

        while (D > currentDay) {
            currentDay += currentGroupSize; // 更新當前天數
            currentGroupSize++; // 更新當前旅行團人數
        }

        printf("%lld\n", currentGroupSize - 1); // 輸出在第D天入住的旅行團人數
    }

    return 0;
}