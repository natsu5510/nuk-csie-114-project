#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(){
	int N;
	scanf("%d", &N);
	int i = 2;//從2開始往後算誰是ugly number
	int c = 1;
	while (i <= N){
		if (N == 1){
			c = 1;
		}
		else{
			if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 6 == 0 || i % 10 == 0 || i % 15 == 0 || i % 30 == 0) {
				c = c + 1;
				i = i + 1;
			}
			else{
				i = i + 1;
			}
		}
	}
	printf("%d", c);
	return 0;
}