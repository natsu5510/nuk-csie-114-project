#include <stdio.h>
#include <math.h>

int main()
{
    int s,a,Day;

    if(s<1){
        s=1;
    }else if(s>10000){
        s=10000;
    }
    if(Day<1){
        Day=1;
    }else if(Day>10^15){
        Day=10^15;
    }
    
    while(scanf("%d %d", &s, &Day)){
            a == Day-s+1;
         printf("%d",&a);
    }
    

}
