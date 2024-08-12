#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(){
	int s; //s為第一組旅行團人數
	int D; //D為第D天查找入住酒店的旅行團人數
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