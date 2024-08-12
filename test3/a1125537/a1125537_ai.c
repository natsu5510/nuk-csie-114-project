#include <stdio.h>

int findGroupSize(long long S, long long D) {
    long long daysPassed = 0;
    while (daysPassed < D) {
        daysPassed += S;  // Add the days of stay for the current group
        S++;              // Increment the group size for the next group
    }
    return S - 1;  // The group size for the day D
}

int main() {
    long long S, D;
    printf("Enter the number of people in the first group (S) and the day to check (D): ");
    scanf("%lld %lld", &S, &D);
    printf("The group size on day %lld is %d.\n", D, findGroupSize(S, D));
    return 0;
}
