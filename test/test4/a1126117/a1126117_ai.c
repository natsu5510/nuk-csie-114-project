#include <stdio.h>
//定義一個函數來求三個數中的最小值
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}


//定義一個函數來求第 n 個 Ugly Number
int getNthUglyNumber(int n) {
    //如果 n 小於等於 0，返回 0
    if (n <= 0) return 0;
    //定義一個數組來存儲 Ugly Number，初始值為 1
    int ugly[n];
    ugly[0] = 1;
    //定義三個指針，分別指向 2、3 和 5 的倍數
    int i2 = 0, i3 = 0, i5 = 0;
    //定義三個變量，分別存儲當前指針乘以對應倍數的值
    int next_multiple_of_2 = 2, next_multiple_of_3 = 3, next_multiple_of_5 = 5;
    //定義一個變量，存儲下一個 Ugly Number
    int next_ugly_number = 1;
    //循環 n-1 次，生成 n-1 個 Ugly Number
    for (int i = 1; i < n; i++) {
        //找出三個變量中的最小值，作為下一個 Ugly Number
        next_ugly_number = min(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5);
        //將下一個 Ugly Number 加入數組
        ugly[i] = next_ugly_number;
        //如果下一個 Ugly Number 等於 2 的倍數，則將 2 的指針向後移動一位，並更新對應的變量
        if (next_ugly_number == next_multiple_of_2) {
            i2++;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        //如果下一個 Ugly Number 等於 3 的倍數，則將 3 的指針向後移動一位，並更新對應的變量
        if (next_ugly_number == next_multiple_of_3) {
            i3++;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        //如果下一個 Ugly Number 等於 5 的倍數，則將 5 的指針向後移動一位，並更新對應的變量
        if (next_ugly_number == next_multiple_of_5) {
            i5++;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }
    //返回第 n 個 Ugly Number
    return next_ugly_number;
}


//主函數
int main() {
    //定義一個變量，存儲用戶輸入的 n
    int n;
    //提示用戶輸入 n
    printf("請輸入一個正整數 n：\n");
    //讀取用戶輸入的 n
    scanf("%d", &n);
    //調用函數，求出第 n 個 Ugly Number
    int result = getNthUglyNumber(n);
    //輸出結果
    printf("第 %d 個 Ugly Number 是 %d\n", n, result);
    //返回 0
    return 0;
}