#include<stdio.h>
#pragma warning(disable:4996) 

int main() {
	int N, i=1, U=1;
	scanf("%d", &N);
	while (U <= N) {
		if (i % 3 == 0 || i % 5 == 0 || i % 2 == 0) {
			U++;
		}
		i++;
	}
	printf("%d", U);
}