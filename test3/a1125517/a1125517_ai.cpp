#include <iostream>
using namespace std;

long long findGroupSize(long long initialSize, long long day) {
    long long currentSize = initialSize;
    long long currentDay = 1;

    while (day > currentSize) {
        day -= currentSize;
        currentSize++;
        currentDay += currentSize;
    }

    return currentSize;
}

int main() {
    long long initialSize, day;

    while (cin >> initialSize >> day) {
        long long groupSize = findGroupSize(initialSize, day);
        cout << groupSize << endl;
    }

    return 0;
}
