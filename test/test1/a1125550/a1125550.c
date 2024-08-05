#include<stdio.h>
#pragma warning(disable:4996)
int main(void){
	int s = 1;
	int d = 1;
	int a = 1;
	scanf("%d %d",&s,&d);
	
	for (int i = 1; i < 10000; i++){
		if (a==i++&&s == i){
			scanf("%d",&a);
			if (d == a){
				printf("a\n");
			}
		}
	}
}