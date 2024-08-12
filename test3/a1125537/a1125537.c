#include<stdio.h>

int main(){
long long s=0,d=0,ans=0;
    while(scanf("%lld%lld",&s,&d)!=EOF){
        while(s<d){
        d-=s;
        s++;
    }
    printf("%lld\n",s);
    }
    return 0;
}
