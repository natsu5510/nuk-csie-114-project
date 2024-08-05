#include <iostream>
using namespace std;

int findGroupSize(int S, long long D) {
    long long currentDay = 1; // Starting from day 1
    int currentGroupSize = S;

    while (true) {
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

    while(cin >> S >> D) {
        cout << findGroupSize(S, D) << endl;
    }

    return 0;
}
