#include <stdio.h>

int min(int a, int b, int c);
int nthUglyNumber(int n);

int min(int a, int b, int c) {
    if (a < b) {
        if (a < c) {
            return a;
        }
        else {
            return c;
        }
    }
    else {
        if (b < c) {
            return b;
        }
        else {
            return c;
        }
    }
}

int nthUglyNumber(int n) {
    int ugly[n];
    int i2 = 0, i3 = 0, i5 = 0;
    int next_multiple_of_2 = 2;
    int next_multiple_of_3 = 3;
    int next_multiple_of_5 = 5;
    int next_ugly_no = 1;

    ugly[0] = 1;

    for (int i = 1; i < n; i++) {
        next_ugly_no = min(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5);
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2) {
            i2++;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if (next_ugly_no == next_multiple_of_3) {
            i3++;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if (next_ugly_no == next_multiple_of_5) {
            i5++;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }

    return next_ugly_no;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", nthUglyNumber(n));
    }

    return 0;
}