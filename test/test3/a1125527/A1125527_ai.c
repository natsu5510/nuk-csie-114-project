#include <stdio.h>

long long find_group_size(long long S, long long D) {
    long long day_count = 0;
    while (day_count < D) {
        day_count += S;
        S++;
    }
    return S - 1;
}

int main() {
    long long S, D;

    // Read the number of test cases
    while (scanf("%lld %lld", &S, &D) != EOF) {
        printf("%lld\n", find_group_size(S, D));
    }

    return 0;
}
		
