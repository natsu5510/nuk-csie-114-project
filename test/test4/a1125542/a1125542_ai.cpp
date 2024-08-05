#include <stdio.h>
#pragma warning(disable:4996)

int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

int findUglyNumber(int n) {
    int ugly[sizeof(n)];
    int i2 = 0, i3 = 0, i5 = 0;
    int next_multiple_of_2 = 2;
    int next_multiple_of_3 = 3;
    int next_multiple_of_5 = 5;

    ugly[0] = 1;

    for (int i = 1; i < n; i++) {
        int next_ugly = min(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5);
        ugly[i] = next_ugly;

        if (next_ugly == next_multiple_of_2) {
            i2++;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if (next_ugly == next_multiple_of_3) {
            i3++;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if (next_ugly == next_multiple_of_5) {
            i5++;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }

    return ugly[n - 1];
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int result = findUglyNumber(n);
    printf("The %dth ugly number is: %d\n", n, result);

    return 0;
}