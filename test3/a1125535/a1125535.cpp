#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
	int s = 0, d = 0;
	int sum = 0;
	scanf("%d %d", &s, d);
	while (s >= 1) {
		sum = sum + s;
		if (d == s) {
			printf("%d", s);
			break;
		}
	}
}