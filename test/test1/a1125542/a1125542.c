#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main(){
	int s, d, i, j, k;
	int A[10000];
	scanf("%d %d\n", &s, &d);
	for (i = 1; i <= 10000; i++){
		for (j = s ; j <= 10000; j++){
			k = k + j*j;
			int A[k] = j;
		}
	}
	printf("%d\n", A[d]);

	system ("pause");
	return 0;
}