#include <stdio.h>

int main() {
    long long S, D;
    
    while (scanf("%11d %11d", &S, &D) == 2)
    {
        long long currentSize = S;
        long long day = 1;
        
        while (day < D)
    {
        day += currentSize;
        currentSize++;
    }
    currentSize--;
    printf("%11d\n", currentSize);
    }
    return 0;
}