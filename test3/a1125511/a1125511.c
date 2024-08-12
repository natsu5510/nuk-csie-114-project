#include <stdio.h>

int main()
{
    int sum;
    int S;
    long long int D;
    while(scanf("%d",&S)!=EOF){
        scanf("%lld",&D);
        sum=0;
        while(sum<D-S){
            sum=sum+S;
            S=S+1;
        }
        printf("%d\n",S);
    }

    return 0;
}
