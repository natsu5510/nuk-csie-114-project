#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996) 
int main() {
	int a,z,p2=0,p3=0,p5=0;
	while (scanf("%d", &a) != EOF){
		p2 = 0, p3 = 0, p5 = 0;
		while (a % 2 == 0){
			p2++;
			a = a / 2;
		}
		while (a % 3 == 0){
			p3 ++ ;
			a = a / 3;
		}
		while (a % 5 == 0){
			p5++;
			a = a / 5;
		}
		z = p5*2+1=
   
		
		printf("%d\n",z);
	}
	return 0 ;
}