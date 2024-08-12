#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
	int enter;
	while (scanf("%d", &enter) != EOF) {
		int ugly[2024] = { 1 };
		int n2 = 0, n3 = 0, n5 = 0;
		for (int i = 1; i < enter;i++) {
			for (;n2 < i;n2++) {
				if (ugly[n2]*2 > ugly[i - 1]) break;
			}
			for (;n3 < i;n3++) {
				if (ugly[n3]*3 > ugly[i - 1]) break;
			}
			for (;n5 < i;n5++) {
				if (ugly[n5]*5 > ugly[i - 1]) break;
			}

			if (ugly[n2] * 2 > ugly[n3] * 3) {
				ugly[i] = ugly[n3] * 3;
			}
			else {
				ugly[i] = ugly[n2] * 2;
			}
			if (ugly[i] > ugly[n5] * 5) {
				ugly[i] = ugly[n5] * 5;
			}
		}
		printf("%d\n", ugly[enter-1]);
	}
	return 0;
}