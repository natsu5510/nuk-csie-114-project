#include <stdio.h>
#include <math.h>

long long findGroupSize(long long S, long long D) {
	long long left = 1, right = 2 * sqrt(D);
	while (left < right) {
		long long mid = left + (right - left) / 2;
		if (mid * (mid + 1) / 2 < D)
			left = mid + 1;
		else
			right = mid;
	}
	return S + left - 1;
}

int main() {
	long long S, D;
	scanf("%lld %lld", &S, &D);
	printf("%lld\n", findGroupSize(S, D));
	return 0;
}
