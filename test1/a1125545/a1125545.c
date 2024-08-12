/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>

int main(){
	int s;
	int d;
	
	scanf("%d%d",&s,&d);
	if (d - s >= 0,d--){
		d = d - s;
		s++;

	}
	printf("%d", s+1);
	return 0;

}
