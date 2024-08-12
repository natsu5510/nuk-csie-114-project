#include <stdio.h>
#include <stdlib.h>

int main()
{
	int S, D;
	while (scanf_s("%d%d", &S, &D) != EOF) {
		int sum = 0,s=0;
		while (sum < D) {
			sum = sum + (S + s);
			if (sum < D) { s++; }
			else { s = s; }
		}
		printf("%d\n", S+s);
	}

}