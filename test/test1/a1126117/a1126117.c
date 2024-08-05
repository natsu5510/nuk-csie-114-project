#include<stdio.h>

int main(){
    int S,D;
    scanf("%d",&S);
    scanf("%d",&D);
    for(;D>S;S++){
        D=D-S;
    }
    printf("%d",S);
    return 0;
}
