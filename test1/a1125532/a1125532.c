#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

int main(){

	int S, D;
	int Sum = 0;
	scanf("%d %d", &S, &D);
	
	Sum = Sum + S;
	while (D <= Sum){
		printf("%d", S);
	}
	S = S + 1;
	
	system("pause");
	return 0;
}