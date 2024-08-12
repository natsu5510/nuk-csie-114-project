#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int n = 0;
	scanf("%d", &n);
	int ugly[2024] = { 0 };
	ugly[0] = 1;
	int i2 = 0, i3 = 0, i5 = 0;
	for (int i = 1; i <= n; i++) {
		if (ugly[i2] * 2 < ugly[i3] * 3) {
			if (ugly[i2] * 2 < ugly[i5] * 5) {
				ugly[i] = ugly[i2] * 2;
				i2++;
			}
			else {
				ugly[i] = ugly[i5] * 5;
				i5++;
			}
		}
		else if (ugly[i3] * 3 < ugly[i2] * 2) {
			if (ugly[i3] * 3 < ugly[i5] * 5) {
				ugly[i] = ugly[i3] * 3;
				i3++;
			}
			else {
				ugly[i] = ugly[i5] * 5;
				i5++;
			}
		}
	}
	printf("%d", ugly[n - 1]);

	return 0;
}