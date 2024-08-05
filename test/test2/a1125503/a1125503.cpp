#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(){
	int N = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N;i++){
		long long int x = 1;
		if (x % 2 == 1 || x % 3 == 1 || x % 5 == 1){
			x = x + 1;
		}
	}
	printf("%lld", x);
	
	return 0;
}