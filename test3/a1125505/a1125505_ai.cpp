#include <iostream>

using namespace std;

long long findGroupSize(long long S, long long D) {
    long long currentDay = 1;
    long long currentGroupSize = S;

    while (currentDay + currentGroupSize <= D) {
        currentDay += currentGroupSize;
        currentGroupSize++;
    }

    return currentGroupSize;
}

int main() {
    long long S, D;

    while (cin >> S >> D) {
        cout << findGroupSize(S, D) << endl;
    }

    return 0;
}
