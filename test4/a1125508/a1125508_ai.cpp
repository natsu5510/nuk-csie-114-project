#include <stdio.h>
#include <stdlib.h>

// �p���Ƥ����̤p��
int min(int a, int b) {
    return (a < b) ? a : b;
}

// ����N��Ugly Number
int findUglyNumber(int n) {
    int* uglyNumbers = (int*)malloc(sizeof(int) * n);
    uglyNumbers[0] = 1; // �Ĥ@��Ugly Number�O1

    int i2 = 0, i3 = 0, i5 = 0; // ���V2�B3�B5���ƪ���m

    for (int i = 1; i < n; ++i) {
        int nextUgly = min(uglyNumbers[i2] * 2, min(uglyNumbers[i3] * 3, uglyNumbers[i5] * 5));
        uglyNumbers[i] = nextUgly;

        // ��s���w��m
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
