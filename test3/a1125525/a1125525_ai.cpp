#include <iostream>

using namespace std;

long long findGroupSize(long long S, long long D) {
    long long currentDay = 1;
    long long currentGroupSize = S;

    while (currentDay + currentGroupSize <= D) {
        // 移至下一個團隊的首日
        currentDay += currentGroupSize;
        // 團隊大小增加
        currentGroupSize++;
    }

    return currentGroupSize;
}

int main() {
    long long S, D;

    // 不斷讀取輸入直到EOF
    while (cin >> S >> D) {
        cout << findGroupSize(S, D) << endl;
    }

    return 0;
}
