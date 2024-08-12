#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

int main(){
	int S = 0; //S表示第一組旅行團人數
	int D = 0; //D表示查詢在第D天的旅行團人數
	int sum = 0; //P表示第D天入住的人數
	scanf("%d %d", &S, &D);

	while (D > S){
		sum = sum + S;
		S = S + 1;
	}
		printf("%d", sum);

		return 0;
		system("pause");
}