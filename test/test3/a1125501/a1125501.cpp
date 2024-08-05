#include <stdio.h> 
#include <stdlib.h>
int main()
{
    int s, d, sum;
    while (scanf_s("%d%d", &s, &d) != EOF)
    {
        sum = s;
        while (sum < d)
        {
            s = s + 1;
            sum = sum + s;
        }
        printf("%d\n", s);
    }
}