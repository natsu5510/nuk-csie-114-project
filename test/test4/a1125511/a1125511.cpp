#include <stdio.h>
#include <stdlib.h>

int isugly(int n){
	while(n%2==0){
		n=n/2;
	}
	while(n%3==0){
		n=n/3;
	}
	while(n%5==0){
		n=n/5;
	}
	return n==1;
}

int num(int a){
	int n=0;
	int t=0;
	while(t<a){
		n++;
		if(isugly(n)){
			t++;
		}
	}
	printf("%d\n",n);
}

int main(){
	
	int a;
	while(scanf("%d",&a)!=EOF){
		num(a);
	}
		
	system("PAUSE");
	return 0;
}
