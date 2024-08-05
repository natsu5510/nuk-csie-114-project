#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int x, y;
    char a;
    char str[100];
    int i;

    // Read input in a loop until EOF
    while (scanf("%d %d %c", &x, &y, &a) != EOF) {
        scanf("%s", str);
        int lost = 0;

        for (i = 0; i < strlen(str); i++) {
            if (a == 'E') {
                if (str[i] == 'F') {
                    x++;
                }
                else if (str[i] == 'R') {
                    a = 'S';
                }
                else if (str[i] == 'L') {
                    a = 'N';
                }
            }
            else if (a == 'W') {
                if (str[i] == 'F') {
                    x--;
                }
                else if (str[i] == 'R') {
                    a = 'N';
                }
                else if (str[i] == 'L') {
                    a = 'S';
                }
            }
            else if (a == 'N') {
                if (str[i] == 'F') {
                    y++;
                }
                else if (str[i] == 'R') {
                    a = 'E';
                }
                else if (str[i] == 'L') {
                    a = 'W';
                }
            }
            else if (a == 'S') {
                if (str[i] == 'F') {
                    y--;
                }
                else if (str[i] == 'R') {
                    a = 'W';
                }
                else if (str[i] == 'L') {
                    a = 'E';
                }
            }

            if (x < 0 || x > m || y < 0 || y > n) {
                if (a == 'E') x--;
                if (a == 'W') x++;
                if (a == 'N') y--;
                if (a == 'S') y++;
                lost = 1;
                break;
            }
        }

        if (lost) {
            printf("%d %d %c LOST\n", x, y, a);
        }
        else {
            printf("%d %d %c\n", x, y, a);
        }
    }

    return 0;
}
