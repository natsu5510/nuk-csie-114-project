#include<stdio.h>

int main(){
    int i,j=2,a=2;
    scanf("%d",&i);
    if(i==1){
        printf("1");
        return 0;
    }
    while(j<=i){
    a++;
    while(!((a%2==0)&&(a%3==0)&&(a%5==0))){
         a++;
    }
    j++;
    }
    printf("%d",a);
    return 0;
}
