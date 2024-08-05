#include <stdio.h>
#include <stdlib.h>
int people(int a, int b){
    int total=0;
    while(total<b){
    total = total+a;
    a++;
    }
    return a;
}
int main()
{
    int S=0;//第一團人數
    int D=0;//第D天
    int result=0;
    scanf("%d %d",&S,&D);
    result = people(S,D);
    result--;
    printf("%d",result);
    return 0;
}
