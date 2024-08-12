#include <stdio.h>
#pragma warning(disable:4996)

int main() {
    int S, D;
    printf("Enter the number of people in the first group (S) and the target day (D): ");
    scanf("%d %d", &S, &D);

    int currentGroup = S;
    int currentDay = 0;

    while (currentDay + currentGroup < D) {
        currentDay += currentGroup;
        currentGroup++;
    }

    printf("The number of people in the group on day %d is %d.\n", D, currentGroup);

    return 0;
}