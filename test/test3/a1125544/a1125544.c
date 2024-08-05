#include<stdio.h>
int main(){
    int s,d,count,save;
    scanf("%d%d",&s,&d);
    count=s;
    while(d>0){
        d=d-s;
        s++;
        count++;
    }
    printf("%d",count-1);
    return 0;
}