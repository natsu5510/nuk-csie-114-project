#include <stdio.h>
#pragma warning(disable:4996)

int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		int	N = 0;
		for (long long int i = 1; ; i++){
			long long int temp = i;
			while (i % 2 == 0){
				i /= 2;
			}
			while (i % 3 == 0){
				i /= 3;
			}
			while (i % 5 == 0){
				i /= 5;
			}
			if (i == 1){
				N++;
				if (N == n){
					printf("%lld\n", temp);
					break;
				}
			}
		}
	}
}