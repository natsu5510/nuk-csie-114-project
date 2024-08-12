#include <stdio.h>

int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

int get_nth_ugly_number(int n) {
    int ugly_numbers[n];
    ugly_numbers[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    int next_multiple_of_2 = 2, next_multiple_of_3 = 3, next_multiple_of_5 = 5;

    for (int i = 1; i < n; i++) {
        int next_ugly_number = min(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5);
        ugly_numbers[i] = next_ugly_number;

        if (next_ugly_number == next_multiple_of_2) {
            i2++;
            next_multiple_of_2 = ugly_numbers[i2] * 2;
        }

        if (next_ugly_number == next_multiple_of_3) {
            i3++;
            next_multiple_of_3 = ugly_numbers[i3] * 3;
        }

        if (next_ugly_number == next_multiple_of_5) {
            i5++;
            next_multiple_of_5 = ugly_numbers[i5] * 5;
        }
    }

    return ugly_numbers[n - 1];
}

int main() {
    int num_cases, n;
    scanf("%d", &num_cases);

    for (int i = 0; i < num_cases; i++) {
        scanf("%d", &n);
        int result = get_nth_ugly_number(n);
        printf("#%d %d\n", i + 1, result);
    }

    return 0;
}