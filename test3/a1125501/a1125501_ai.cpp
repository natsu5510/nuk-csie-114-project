#include <stdio.h>

long long findGroupSize(int S, long long D) {
    long long currentDay = 1; // Starting from day 1
    int currentGroupSize = S;

    while (1) {
        // Calculate the day the current group will leave
        long long leaveDay = currentDay + currentGroupSize - 1;

        // Check if the given day D is during the current group's stay
        if (D >= currentDay && D <= leaveDay) {
            return currentGroupSize;
        }

        // Move to the next group
        currentDay = leaveDay + 1;
        currentGroupSize++;
    }
}

int main() {
    int S;
    long long D;

    while(scanf("%d %lld", &S, &D) != EOF) {
        printf("%lld\n", findGroupSize(S, D));
    }

    return 0;
}
