#include<stdio.h>
int main(){
	int N, a;
	array [a] = a;
	while (scanf_s("%d",&N)!=EOF){
		for (a = 1; a <= 2023; a++){
			if (a % 2 != 0 || a % 5 != 0 || a % 3 != 0){
				array[a] = a + 1;
			}
		}
		printf("%d", array[N]);

	}
	return 0;
}