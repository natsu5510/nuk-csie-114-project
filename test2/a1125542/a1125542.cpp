#include<stdlib.h>
pragma warning(disable:4996)

int main(){
	int n;
	int A[100000];
	while (scanf("%d", &n)!= EOF){
		for (long long int i = 0; i <=100000; i++){
			if (i % 2 || i % 3 || i % 5 || i == 1){
				for (int j = 1; j <= i; j++){
					A[j] = i;
				}
			}
			printf("%d\n", A[n]);
		}
	}
	
	
	return 0;
}