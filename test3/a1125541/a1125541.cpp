#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int S, D;
	while (scanf("%d%d", &S, &D) != EOF){
		while (D > 0) {
			D -= S;
			S++;
		}
		printf("%d\n", S - 1); 
	}
	return 0;
}