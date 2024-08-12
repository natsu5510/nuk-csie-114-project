#include <stdio.h>

int min(int a, int b, int c) {
    int min = a < b ? a : b;
    return min < c ? min : c;
}

int get_ugly_number(int n) {
    int ugly_numbers[2023];
    ugly_numbers[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    int next_multiple_of_2 = 2;
    int next_multiple_of_3 = 3;
    int next_multiple_of_5 = 5;

    for (int i = 1; i < n; ++i) {
        int next_ugly_number = min(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5);
        ugly_numbers[i] = next_ugly_number;

        if (next_ugly_number == next_multiple_of_2) {
            ++i2;
            next_multiple_of_2 = ugly_numbers[i2] * 2;
        }

        if (next_ugly_number == next_multiple_of_3) {
            ++i3;
            next_multiple_of_3 = ugly_numbers[i3] * 3;
        }

        if (next_ugly_number == next_multiple_of_5) {
            ++i5;
            next_multiple_of_5 = ugly_numbers[i5] * 5;
        }
    }

    return ugly_numbers[n - 1];
}

int main() {
    int N;
    printf("請輸入正整數 N (1 <= N <= 2023): ");
    scanf_s("%d", &N);

    int result = get_ugly_number(N);
    printf("第%d個Ugly Number為：%d\n", N, result);

    return 0;
}