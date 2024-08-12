#include <stdio.h>

int main() {
    int n, times = 1, num = 0, record = 0;

    while (scanf("%d", &n) != EOF)
    {
        while (times <= n) {
            num = num + 1;
            record = num;

            while (num > 1) {
                if (num % 2 == 0) {
                    num = num / 2;
                }
                else if (num % 3 == 0) {
                    num = num / 3;
                }
                else if (num % 5 == 0) {
                    num = num / 5;
                }
                else {
                    break;
                }
            }

            if (num == 1) {
                times += 1;
            }

            num = record;
        }

        printf("%d\n", num);
    }

    return 0;
}