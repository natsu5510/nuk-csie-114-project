#include <iostream>
#include <cmath>

using namespace std;

long long solve(long long S, long long D) {
    long long left = S, right = 2e4;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (mid * (mid + 1) / 2 - S * (S - 1) / 2 >= D)
            right = mid;
        else
            left = mid + 1;
    }
    return right;
}

int main() {
    long long S, D;
    while (cin >> S >> D) {
        cout << solve(S, D) << endl;
    }
    return 0;
}
