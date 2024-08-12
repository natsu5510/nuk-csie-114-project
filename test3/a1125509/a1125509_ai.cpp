
/*4.0*/
#include <stdio.h>

long long S, D;

long long solve(long long left, long long right) {
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        if (mid * (mid + 1) / 2 >= D)
            right = mid;
        else
            left = mid;
    }
    return right;
}

int main() {
    scanf("%lld %lld", &S, &D);
    long long right = solve(0, 1000000000000);
    if (S > right)
        printf("%lld\n", S + right - 1);
    else {
        long long rem = D - right * (right - 1) / 2;
        if (rem <= S)
            printf("%lld\n", right - 1);
        else
            printf("%lld\n", right);
    }
    return 0;
}

