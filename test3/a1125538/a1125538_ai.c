#include <stdio.h>

long long groupSizeOnDay(long long S, long long D) {
    long long day = 1;
    long long groupSize = S;

    while (day + groupSize <= D) {
        day += groupSize;
        groupSize++;
    }

    return groupSize;
}

int main() {
    long long S, D;

    // Reading input from stdin
    while (scanf("%lld %lld", &S, &D) != EOF) {
        long long result = groupSizeOnDay(S, D);
        printf("%lld\n", result);
    }

    return 0;
}
