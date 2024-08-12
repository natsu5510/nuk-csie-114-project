#include <iostream>

long long findGroupNumber(long long S, long long D) {
    long long current_day = 1;
    long long group_number = S;

    while (current_day + group_number <= D) {
        current_day += group_number;
        group_number += 1;
    }

    return group_number;
}

int main() {
    long long S, D;

    // Example inputs
    std::cin >> S >> D;
    std::cout << findGroupNumber(S, D) << std::endl;

    return 0;
}