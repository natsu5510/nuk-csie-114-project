#include<stdio.h>
#pragma warning(disable:4996)
int main(){
	int s,d;
	while (scanf("%d %d", &s, &d)!=EOF){
		int t=0;
		while (1){
			t += s;
			if (t >= d){
				printf("%d\n", s);
				break;
			}
			s++;
		}
	}
}