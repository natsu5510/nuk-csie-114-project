
#include <stdio.h>

int main() {
    unsigned long long int n;
    int ans = 1,i = 2 ,j = 0 ,
    scanf("%d",&n);
    if (n==1){
        printf("1");
    }
    while (time < n){
        if(i%2==0){
            i/2;
        }
        if(i%3==0){
            i/3;
        }
        if(i%5==0){
            i/5;
        }
    }printf(ans);
}