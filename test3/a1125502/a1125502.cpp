#include <stdio.h>

long long find_travel_group(int S, long long D) {
    long long current_group_size = S;
    long long day = 1;

    while (day < D) {
        current_group_size++;
        day += current_group_size;
    }

    return current_group_size;
}

int main() {
    int S;
    long long D;

    while (scanf_s("%d %lld", &S, &D) != EOF) {
        long long result = find_travel_group(S, D);
        printf("%lld\n", result);
    }

    return 0;
}