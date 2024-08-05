#include <stdio.h>

// Function to calculate the group size based on the given rules
int calculateGroupSize(int initialSize, int day) {
    int groupSize = initialSize;
    int dayCounter = 1;

    while (dayCounter < day) {
        groupSize++;
        dayCounter += groupSize;
    }

    return groupSize;
}

int main() {
    // Input: Initial group size and the specified day
    int initialSize, specifiedDay;

    printf("Enter the initial group size: ");
    scanf("%d", &initialSize);

    printf("Enter the specified day: ");
    scanf("%d", &specifiedDay);

    // Calculate the group size staying in the hotel on the specified day
    int result = calculateGroupSize(initialSize, specifiedDay);

    // Output the result
    printf("On day %d, the group size staying in the hotel is: %d\n", specifiedDay, result);

    return 0;
}

