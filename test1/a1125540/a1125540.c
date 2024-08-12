#include<stdio.h>


int main() {
    int S, D;
    scanf("%d %d", &S, &D);
    do {
        D = D - S;
        S++;
    } while (D > 0);
    printf("%d", S-1);
    return 0;
}
