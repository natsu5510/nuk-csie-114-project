#include<stdio.h>
#pragma warning(disable:4996)

int main() {
    int N = 0;
    while (scanf("%d", &N)) {
        int num = 0, count = 0;
        for (num = 1; count < N;num++) {
            int k = num;
            while (k % 2 == 0)
                k /= 2;
            while (k % 3 == 0)
                k /= 3;
            while (k % 5 == 0)
                k /= 5;

            if (k == 1) {
                count++;
                continue;
            }
            else {
                continue;
            }
        }
        num -= 1;
        printf("%d\n", num);
    }
    return 0;
}