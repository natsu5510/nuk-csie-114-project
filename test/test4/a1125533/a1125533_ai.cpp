#include <iostream>
#include <vector>

using namespace std;

bool isUgly(int num) {
    while (num % 2 == 0) {
        num /= 2;
    }
    while (num % 3 == 0) {
        num /= 3;
    }
    while (num % 5 == 0) {
        num /= 5;
    }
    return num == 1;
}

int findUglyNumber(int n) {
    vector<int> uglyNumbers = { 1 };
    int i = 2;

    while (uglyNumbers.size() < n) {
        if (isUgly(i)) {
            uglyNumbers.push_back(i);
        }
        i++;
    }

    return uglyNumbers.back();
}

int main() {
    int n = 2023; // Specific input value

    int result = findUglyNumber(n);
    cout << "The " << n << "th ugly number is: " << result << endl;

    return 0;
}