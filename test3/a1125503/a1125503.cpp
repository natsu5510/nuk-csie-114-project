#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(){
	int s; //s���Ĥ@�ծȦ�ΤH��
	int D; //D����D�Ѭd��J��s�����Ȧ�ΤH��
	while (scanf("%d%d", &s, &D) != EOF) {
		int sum = 0;
		while (sum < D){
			sum = sum + s;
			s = s + 1;
		}
		printf("%d\n", s - 1);
	}

	return 0;
}