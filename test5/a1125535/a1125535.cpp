#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	int m, n, x, y, i, x2, y2;
	int dir;
	char c, ori[4];
	int move[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };
	char walk[101];
	int scent[51][51] = { 0 };

	scanf("%d %d", &m, &n);
	while (scanf("%d %d %c", &x, &y, &c) != EOF) {
		getchar();
		for (dir = 0; dir < 4; dir++) {
			if (c == ori[dir]) break;
		}
		gets_s(walk);
		for (i = 0; i < strlen(walk); i++) {
			if (walk[i] == 'F') {
				x2 = x + move[dir][0];
				y2 = y + move[dir][1];

				if (x2<0 || y2<0 || x2>m || y2>n) {
					if (scent[x][y] == 0) {
						scent[x][y] = 1;
						printf("%d %d %c LOST\n",x, y, ori[dir]);
						break;
					}
				}
				else {
					x = x2;
					y = y2;
				}
			}
			if (walk[i] == 'R') {
				dir = (dir + 1) % 4;
			}
			if (walk[i] == 'L') {
				dir = (dir + 3) % 4;
			}
		}
		if (i == strlen(walk)) {
			printf("%d %d %c", x, y.ori[dir]);
		}
	}
}