#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s,d,ans;
    while(scanf("%d %d",&s,&d)){
        int day=1;
        while(day<=d)
        {
            day+=s;
            s++;
        }
        s--;
        printf("%d\n",s);
    }


    return 0;
}
