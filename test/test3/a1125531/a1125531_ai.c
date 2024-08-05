#include <stdio.h>

int main() {
    long long S, D;  // Using long long to handle large integers

    // Input the initial group size (S) and the day (D)
    scanf("%lld %lld", &S, &D);

    // Calculate the group size on the D-th day
    long long currentGroup = S;
    long long daysStayed = 1;

    while (daysStayed < D) {
        currentGroup++;
        daysStayed += currentGroup;
    }

    // Output the result
    printf("%lld\n", currentGroup);

    return 0;
}
