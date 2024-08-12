#include <stdio.h>

int findGroupSize(int S, long long D) {
    long long currentDay = 1; // Start from day 1
    int currentGroupSize = S; // Initial group size

    // Loop until the current day reaches or exceeds D
    while (currentDay + currentGroupSize <= D) {
        currentDay += currentGroupSize; // Move to the next group's start day
        currentGroupSize++; // Increment group size
    }

    return currentGroupSize; // Return the size of the group on the D-th day
}

int main() {
    int S;
    long long D;

    // Read S and D from input
    while (scanf("%d %lld", &S, &D) == 2) {
        // Output the result
        printf("%d\n", findGroupSize(S, D));
    }

    return 0;
}
