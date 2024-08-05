#include <stdio.h>

// Function to find the size of the group staying in the hotel on the D-th day
long long find_group_size(long long S, long long D) {
    long long current_day = 1;
    long long current_group_size = S;

    // Iterate through the groups until the desired day is reached
    while (current_day + current_group_size <= D) {
        current_day += current_group_size;
        current_group_size++;
    }

    return current_group_size;
}

int main() {
    long long S, D;

    // Read input pairs of S and D until end of file
    while (scanf("%lld %lld", &S, &D) != EOF) {
        printf("%lld\n", find_group_size(S, D));
    }

    return 0;
}
