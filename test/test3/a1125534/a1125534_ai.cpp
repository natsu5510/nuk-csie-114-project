#include <stdio.h>
#pragma warning (disable:4996)

int main() {
    long long s, d;
    scanf("%lld %lld", &s, &d);
    while (d > 0) {
        d -= s;
        s++;
    }
    printf("%lld\n", s - 1);
    return 0;
}