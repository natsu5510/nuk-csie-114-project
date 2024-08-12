#include<stdio.h>

int main(){
int n=0;
while(scanf("%d",&n)!=EOF){
long long int k=2;
long long int num=0;
    if(n==1){
    printf("%d\n",n);
    }
    for(long long int i=2;i<=n;i++){
        num=k;
    while(num%2==0){
        num=num/2;
        }
     while(num%3==0){
        num=num/3;
        }
     while(num%5==0){
        num=num/5;
        }
    if(num!=1){
        i--;
        }
        k++;
    }
    k--;
     printf("%lld\n",k);
}
return 0;
}
