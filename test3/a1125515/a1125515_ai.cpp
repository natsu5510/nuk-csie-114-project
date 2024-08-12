#include <stdio.h>

int main() {
    long long S, D, H;

    while (scanf("%lld %lld", &S, &D) == 2) {
        H = S;
        while (H < D) {
            D -= H;
            H++;
        }

        printf("%lld\n", H);
    }

    return 0;
}
