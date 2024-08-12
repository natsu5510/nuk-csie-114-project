#include <stdio.h>
int main()
{
    int s,d;
    scanf("%d%d",&s,&d);
    while(d>s){
        d-=s;
        s++;
    }
    printf("%d",s);
}
