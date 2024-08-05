#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,s,d;
    scanf("%d %d",&s,&d);
    while(x<d)
    {
        x=x+s;
        s++;
    }
    s--;
    printf("%d",s);

    return 0;
}
