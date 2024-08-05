#include<stdio.h>


int ugly_or_not(int a);

int main() {
    int examination, i, n, ugly[10000] = {0}, counter = 0;
    scanf("%d", &n);
    for (i = 1; i < 10000; i++) {
        examination = ugly_or_not(i);
        if (examination == 1) {
            ugly[counter] = i;
            counter++;
        }
    }

    for (i = 0; i < 10000; i++) {
        printf("%d ", ugly[i]);
    }

    printf("%d", ugly[n-1]);
    return 0;
}

int ugly_or_not(int a) {
    while (a % 2 == 0) {
        a = a / 2;
    }
    while (a % 3 == 0) {
        a = a / 3;
    }
    while (a % 5 == 0) {
        a = a / 5;
    }
    if (a == 1) {
        return 1;
    }
    else return 0;
}
