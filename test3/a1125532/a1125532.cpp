#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
	int S = 0;//��1�ΤH��
	int D = 0;//��D�Ѧb�������H��
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