#include <stdio.h>
#pragma warning(disable:4996)

int main(){
	int N;
	scanf("%d", &N);
	if (N >= 1 && N <= 2023){
		for (int i = 1; i <= N; i++){
			long n;
			if (n / 2 != 0 || n / 3 != 0 || n / 5 != 0){
				return 0;
			}
		}
	}
	printf("%d", n);
	else {
		return 0;
	}
	return 0;
}