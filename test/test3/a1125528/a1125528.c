#include <stdio.h>

int main() {
    long long s, d;
    while(scanf("%lld %lld", &s, &d)==2)
    {
        long long l=s, sum=0;
        while(1)
        {
            sum+=l;
            if(sum >= d)
            {
                printf("%lld\n", l);
                break;
                
            }
            l++;
            
        }
    }
    return 0;
}