#include <stdio.h>
#include <stdlib.h>

// 計算兩數中的最小值
int min(int a, int b) {
    return (a < b) ? a : b;
}

// 找到第N個Ugly Number
int findUglyNumber(int n) {
    int* uglyNumbers = (int*)malloc(sizeof(int) * n);
    uglyNumbers[0] = 1; // 第一個Ugly Number是1

    int i2 = 0, i3 = 0, i5 = 0; // 指向2、3、5倍數的位置

    for (int i = 1; i < n; ++i) {
        int nextUgly = min(uglyNumbers[i2] * 2, min(uglyNumbers[i3] * 3, uglyNumbers[i5] * 5));
        uglyNumbers[i] = nextUgly;

        // 更新指針位置
        if (nextUgly == uglyNumbers[i2] * 2) i2++;
        if (nextUgly == uglyNumbers[i3] * 3) i3++;
        if (nextUgly == uglyNumbers[i5] * 5) i5++;
    }

    int result = uglyNumbers[n - 1];
    free(uglyNumbers);
    return result;
}

int main() {
    int N;

    while (scanf("%d", &N) != EOF) {
        int result = findUglyNumber(N);
        printf("%d\n", result);
    }


    return 0;
}
