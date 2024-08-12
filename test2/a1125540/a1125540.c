#include<stdio.h>


int main() {
    int N, j = 1;
    int ugly_number, i;
    int v[10000] = {0};
    while (1) {
        scanf("%d", &N);
        for (i = 1; i <= 10000; i++) {
            if (i%2==0 || i%3==0 || i%5==0) {
                v[j] = i;
                j++;
            }
        }
        printf("%d", v[N+1]);
    }
    return 0;
}


