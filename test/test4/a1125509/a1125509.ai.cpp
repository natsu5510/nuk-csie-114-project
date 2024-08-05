#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<long long> uglyNumbers;
    uglyNumbers.push_back(1);

    int n = 1500; // Generate the first 1500 ugly numbers

    for (long long i = 2; uglyNumbers.size() < n; ++i) {
        long long num = i;

        // Divide by 2, 3, and 5 until no longer divisible
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;

        // If the remaining number is 1, it's an ugly number
        if (num == 1) uglyNumbers.push_back(i);
    }

    int input;
    while (cin >> input && input != 0) {
        cout << uglyNumbers[input - 1] << endl;
    }

    return 0;
}