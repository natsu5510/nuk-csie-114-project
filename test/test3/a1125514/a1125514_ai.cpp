#include <iostream>

using namespace std;

long long calculateGroupSize(long long S, long long D) {
    long long currentSize = S;
    long long currentDay = 1;

    while (D > currentDay) {
        currentSize++;
        currentDay += currentSize;
    }

    return currentSize;
}

int main() {
    long long S, D;

    while (cin >> S >> D) {
        long long result = calculateGroupSize(S, D);
        cout << result << endl;
    }

    return 0;
}
