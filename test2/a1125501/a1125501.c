#include <stdio.h>
int main ()
{
    double N,i=0,a,b,c;
    while (scanf("%f",&N) != EOF)
    {
        for (i=1;i<=N;i++)
        {
            if (i%1==i)
                {i=i+1};
                a=i/2;
            if (a%1==a)
                {i=i+1};
                b=i/3;
            if(b%1==b)
                {i=i+1};
                c=i/5;
            if(c%1==c)
                {i=i+1};
        }
        printf("%d",i);
    }
    return 0;
}
