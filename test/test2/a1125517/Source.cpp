#include<iostream>
using namespace std;
int main(){
	int a;
	while(scanf("%d",&a)!=EOF){
		int n=0;
		long long int x=0;
		while(n<a){
		    x++;
			long long int k=x;
			while(k%2==0)k/=2;
			while(k%3==0)k/=3;
			while(k%5==0)k/=5;
			if(k==1)n++;
		}
		cout<<x<<endl;
	}
}