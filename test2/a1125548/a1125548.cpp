#include <stdio.h>

int main() {
    int  exp[2022] = { 0 }, n, count = 0;
    long max = 0, i = 0;
    while (scanf("%d", &n) != EOF) {//��Jn
        if (exp[n - 1] != 0) {//�p�G���e��L�N������X
            printf("%d\n", exp[n - 1]);
        }
        else {
            for (int count = 0; count < n; count++) {//�p���count��ugly number
                for ( i=max ; i > 0; i++){
                    if (i > max)max = i;
                    while (i % 2 == 0) {
                        i = i / 2;
                    }
                    while (i % 3 == 0) {
                        i = i / 3;
                    }
                    while (i % 5 == 0) {
                        i = i / 5;
                    }
                    if (i == 1) exp[count] = i;
                }
            }
            printf("%d\n", exp[n - 1]);
        }
    }
    return 0;
}