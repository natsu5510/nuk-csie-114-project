這是一個解決UVA136 - UglyNumbers問題的C語言程式碼。該程式會找出第N個UglyNumber。

#include <stdio.h>

unsigned getNthUglyNo(unsigned n) {
	unsigned ugly[n]; // 初始化一個列表來存儲ugly numbers
	unsigned i2 = 0, i3 = 0, i5 = 0;
	unsigned next_multiple_of_2 = 2;
	unsigned next_multiple_of_3 = 3;
	unsigned next_multiple_of_5 = 5;
	unsigned next_ugly_no = 1;

	ugly[0] = 1; // 第一個ugly number是1

	for (int i = 1; i < n; i++) {
		next_ugly_no = min(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5);
		ugly[i] = next_ugly_no;
		if (next_ugly_no == next_multiple_of_2) {
			i2 = i2 + 1;
			next_multiple_of_2 = ugly[i2] * 2;
		}
		if (next_ugly_no == next_multiple_of_3) {
			i3 = i3 + 1;
			next_multiple_of_3 = ugly[i3] * 3;
		}
		if (next_ugly_no == next_multiple_of_5) {
			i5 = i5 + 1;
			next_multiple_of_5 = ugly[i5] * 5;
		}
	}
	return next_ugly_no;
}

unsigned min(unsigned a, unsigned b, unsigned c) {
	if (a <= b) {
		if (a <= c)
			return a;
		else
			return c;
	}
	if (b <= c)
		return b;
	else
		return c;
}

int main() {
	unsigned no = getNthUglyNo(150);
	printf("150th ugly no. is %d ", no);
	getchar();
	return 0;
}