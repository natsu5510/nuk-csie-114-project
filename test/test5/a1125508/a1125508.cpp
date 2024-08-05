#include <stdio.h>
#include<stdlib.h>
#include<string.h>

char ins[102], sc[52][2];

int main() {
	int m, n, x, y, xx, yy, i, j, cnt = 0, p;
	char c;
	scanf_s("%d%d", &m, &n);
	while (scanf_s("%d%d %c\n", &x, &y, &c) != EOF) {
		gets_s(ins);
		p = 0;
		for (i = 0; i<strlen(ins); i++) {
			xx = x, yy = y;
			if (ins[i] == 'R') {
				if (c == 'N')c = 'E';
				else if (c == 'E')c = 'S';
				else if (c == 'S')c = 'W';
				else if (c == 'W')c = 'N';
			}
			else if (ins[i] == 'L') {
				if (c == 'N')c = 'W';
				else if (c == 'E')c = 'N';
				else if (c == 'S')c = 'E';
				else if (c == 'W')c = 'S';
			}
			else if (ins[i] == 'F') {
				if (c == 'N')y += 1;
				else if (c == 'E')x += 1;
				else if (c == 'S')y -= 1;
				else if (c == 'W')x -= 1;
			}
			for (j = 0; j<cnt; j++) {
				if (x == sc[j][0] && y == sc[j][1]) {
					x = xx, y = yy;
					break;
				}
			}
			if (x<0 || x>m || y<0 || y>n) {
				sc[cnt][0] = x, sc[cnt][1] = y;
				if (c == 'N')y--;
				else if (c == 'E')x--;
				else if (c == 'S')y++;
				else if (c == 'W')x++;
				cnt++;
				p = 1;
				break;
			}
			if (p)break;
		}
		printf("%d %d %c", x, y, c);
		if (p)printf(" LOST");
		printf("\n");
	}
	return 0;
}