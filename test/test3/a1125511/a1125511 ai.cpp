#include <stdio.h>

int main() {
    long long S, D;
    while (scanf("%lld %lld", &S, &D) != EOF) {
        while (D > S) {
            D -= S;
            S++;
        }
        printf("%lld\n", S);
    }
    return 0;
}

