#include <iostream>
using namespace std;

int main() {
    long long S, D;
    while (cin >> S >> D) {
        long long totalDays = 0;
        long long groupSize = S;

        while (totalDays < D) {
            totalDays += groupSize;
            if (totalDays < D) {
                groupSize++; // Move to the next group
            }
        }

        cout << groupSize << endl;
    }
    return 0;
}
