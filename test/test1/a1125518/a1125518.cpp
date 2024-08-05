#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

int main() {
	int S, D, a;
	scanf("%d %d", &S, &D);
	a = S;
	
	while (a < D){
			S++;
			a += S;
	}

	printf("%d\n", S);
	system("pause");
}