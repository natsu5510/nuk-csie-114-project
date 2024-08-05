#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);
	int i = n / 4;
	int j = n % 4;
	printf("%d", (i + 1) * (n + 6));

	return 0;

}