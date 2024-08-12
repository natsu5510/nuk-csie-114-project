#include<stdio.h>
#pragma warning(disable:4996)
int main(void){
	int N;
	int a;
	scanf("%d", &N);
	for (int i = 1; i <=N; i++){
		if ((a[i] % 2 == 0) || (a[i] % 3 == 0) || (a[i] % 5 == 0)){
			a[i] = a[i+1];
			
			if (i == N){
				printf("%d", a[i]);
			}
		}
	}
	return 0;
}