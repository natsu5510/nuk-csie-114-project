#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdbool.h>

// 判斷一個數是否為 Ugly Number
bool is_ugly(int n) {
    // 如果 n 為 0 或負數，則不是 Ugly Number
    if (n <= 0) {
        return false;
    }
    // 如果 n 為 1，則是 Ugly Number
    if (n == 1) {
        return true;
    }
    // 不斷除以 2, 3, 5，直到無法整除或為 1
    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    while (n % 5 == 0) {
        n /= 5;
    }
    // 如果最後 n 為 1，則是 Ugly Number，否則不是
    return n == 1;
}

// 求出第 n 個 Ugly Number
int nth_ugly(int n) {
    // 如果 n 為 0 或負數，則返回 -1 表示錯誤
    if (n <= 0) {
        return -1;
    }
    // 用一個變數 i 來記錄當前的數，用一個變數 count 來記錄已經找到的 Ugly Number 的個數
    int i = 1, count = 0;
    // 當 count 小於 n 時，不斷增加 i 並判斷是否為 Ugly Number
    while (count < n) {
        if (is_ugly(i)) {
            // 如果是 Ugly Number，則 count 加一
            count++;
        }
        // i 加一
        i++;
    }
    // 返回 i - 1，即第 n 個 Ugly Number
    return i - 1;
}

// 主函數
int main() {
    // 定義一個變數 n 來存儲輸入的數
    int n;
    // 用一個迴圈來讀取輸入，直到遇到 EOF
    while (scanf("%d", &n) != EOF) {
        // 調用 nth_ugly 函數來求出第 n 個 Ugly Number
        int ans = nth_ugly(n);
        // 輸出答案，格式為 "第 n 個 Ugly Number 為 ans"
        printf("第 %d 個 Ugly Number 為 %d\n", n, ans);
    }
    // 返回 0 表示正常結束
    return 0;
}