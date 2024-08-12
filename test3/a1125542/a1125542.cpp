#include<stdlib.h>
#include<stdio.h>
#pragma warning(disable:4996)

int main() {
    long int s;
    long int d;
    
    while (scanf("%d %d", &s, &d) != EOF) {
        while (d != 0) {
            d = d - s;
            if (d <= 0) {
                printf("%d\n", s);
                break;
            }
            else s++;
        }
    }
    return 0;
}