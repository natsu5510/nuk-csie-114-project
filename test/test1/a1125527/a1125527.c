#include <stdio.h>

int main() {
    long long S, D;
    
    while (scanf("%lld %lld", &S, &D) == 2)
    {
        long long currentSize = S;
        long long day = 1;
        
        while (day < D) 
        { 
        day += currentSize;
        currentSize++;
    }
        currentSize--;
    printf("%lld\n", currentSize);
    }

    return 0;
}
