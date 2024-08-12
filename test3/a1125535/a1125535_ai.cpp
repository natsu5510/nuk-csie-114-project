#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long long findGroupSize(int S, long long D) {
    int currentGroupSize = S;
    long long currentDay = 1;

    while (1) {
        if (currentDay == D) {
            return currentGroupSize;
        }
        currentGroupSize++;
        currentDay += currentGroupSize;
    }
}

int main() {
    int S;
    long long D;

    scanf("%d %lld", &S, &D);

    long long result = findGroupSize(S, D);
    printf("%lld\n", result);

    return 0;
}
