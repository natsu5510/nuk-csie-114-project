#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned getNthUglyNumber(int n) {
    if (n == 1) return 1;

    vector<unsigned> uglyNumbers(n);
    uglyNumbers[0] = 1;

    int index2 = 0, index3 = 0, index5 = 0;
    unsigned nextMultipleOf2 = 2;
    unsigned nextMultipleOf3 = 3;
    unsigned nextMultipleOf5 = 5;
    unsigned nextUglyNumber = 1;

    for (int i = 1; i < n; i++) {
        nextUglyNumber = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
        uglyNumbers[i] = nextUglyNumber;

        if (nextUglyNumber == nextMultipleOf2) {
            index2++;
            nextMultipleOf2 = uglyNumbers[index2] * 2;
        }
        if (nextUglyNumber == nextMultipleOf3) {
            index3++;
            nextMultipleOf3 = uglyNumbers[index3] * 3;
        }
        if (nextUglyNumber == nextMultipleOf5) {
            index5++;
            nextMultipleOf5 = uglyNumbers[index5] * 5;
        }
    }

    return nextUglyNumber;
}

int main() {
    int n;
    while (cin >> n) {
        cout << getNthUglyNumber(n) << endl;
    }
    return 0;
}
