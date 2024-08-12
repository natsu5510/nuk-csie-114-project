#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996)

int main() {
    int n, m;//長寬
    int O_x, O_y;//原位置
    char D[2];//原方位
    char C[1000];//指令
    char pre[100][100] = {};
    scanf("%d %d", &n, &m);
    while (scanf("%d %d %s", &O_x, &O_y, D) == 3) {
        scanf("%s", C);
        int d = D[0];
        bool flag = false;
        for (int i = 0; C[i]; i++) {
            if (C[i] == 'F') {
                switch (d) {
                case 'N': O_y++; break;
                case 'E':O_x++; break;
                case 'W':O_x--; break;
                case 'S':O_y--; break;
                }
            }
            else if (C[i] == 'R') {
                switch (d) {
                case 'N':d = 'E'; break;
                case 'E':d = 'S'; break;
                case 'W':d = 'N'; break;
                case 'S':d = 'W'; break;
                }
            }
            else {
                switch (d) {
                case 'N':d = 'W'; break;
                case 'E':d = 'N'; break;
                case 'W':d = 'S'; break;
                case 'S':d = 'E'; break;
                }
            }
            if (O_x < 0 || O_y < 0 || O_x > n || O_y > m) {
                switch (d) {
                case 'N':O_y--; break;
                case 'E':O_x--; break;
                case 'W':O_x++; break;
                case 'S':O_y++; break;
                }
                if (pre[O_x][O_y] == 1)
                    continue;
                flag = true;
                pre[O_x][O_y] = 1;
                break;
            }
        }
        if (!flag)
            printf("%d %d %c\n", O_x, O_y, d);
        else {
            printf("%d %d %c LOST\n", O_x, O_y, d);
        }
    }
    return 0;
}