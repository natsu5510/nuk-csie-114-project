#include <stdio.h>

long findGroupSize(long S, long long D) {
    long long totalDaysPassed = 0;
    long currentGroupSize = S;

    // Loop until the total days passed reaches or exceeds the target day D
    while (totalDaysPassed < D) {
        // Add the current group size to the total days passed
        totalDaysPassed += currentGroupSize;

        // If the total days passed still hasn't reached the target day, move to the next group
        if (totalDaysPassed < D) {
            currentGroupSize++;
        }
    }

    return currentGroupSize;
}

int main() {
    long S;
    long long D;

    // Read input until EOF
    while (scanf("%ld %lld", &S, &D) != EOF) {
        long groupSize = findGroupSize(S, D);
        printf("On day %lld, the group size is: %ld\n", D, groupSize);
    }

    return 0;
}
