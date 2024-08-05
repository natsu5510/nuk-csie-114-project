#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s,d,st;
    while(scanf("%d %d",&s,&d) != EOF){
        st = s;
        while (1){
            d = d-st;
            if(d <= 0){
                printf("%d\n",st);
                break;
            }
            st++;
        }
    }
    return 0;
}
