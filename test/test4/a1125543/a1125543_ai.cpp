#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int n;
	printf("請輸入一個正整數N：");
	scanf("%d", &n);
	int ugly[n];
	ugly[0] = 1;
	int i2 = 0, i3 = 0, i5 = 0;
	int next_multiple_of_2 = 2;
	int next_multiple_of_3 = 3;
	int next_multiple_of_5 = 5;
	int next_ugly_no = 1;
	for (int i = 1; i < n; i++) {
		next_ugly_no = (next_multiple_of_2 < next_multiple_of_3) ? next_multiple_of_2 : next_multiple_of_3;
		next_ugly_no = (next_ugly_no < next_multiple_of_5) ? next_ugly_no : next_multiple_of_5;
		ugly[i] = next_ugly_no;
		if (next_ugly_no == next_multiple_of_2) {
			i2++;
			next_multiple_of_2 = ugly[i2] * 2;
		}
		if (next_ugly_no == next_multiple_of_3) {
			i3++;
			next_multiple_of_3 = ugly[i3] * 3;
		}
		if (next_ugly_no == next_multiple_of_5) {
			i5++;
			next_multiple_of_5 = ugly[i5] * 5;
		}
	}
	printf("第%d個ugly number是%d。\n", n, ugly[n - 1]);
	return 0;
}