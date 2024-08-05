#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c, i, d, x;
	c = 0;
	x = 0;

    while(1)
    {
        scanf("%d %d", &a, &b);
        d = 1;
        while(d<=b)
        {
            d+=a;
            a++;
        }
        printf("%d",a-1);






}}
