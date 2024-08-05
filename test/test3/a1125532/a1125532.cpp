#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
	int S = 0;//第1團人數
	int D = 0;//第D天在飯店的人數
	while (scanf("%d %d", &S, &D) != EOF){
		int Sum = 0;
		int a = 0;
		for (int i = 0; Sum < D; i++){
			Sum = Sum + S + i;
			a = i;
		}
		printf("%d\n", S + a);
	}
	return 0;
}