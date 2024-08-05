#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int s = 0, d = 0;
	int ans = 0;
	scanf("%d %d", &s, &d);
	while (ans < d) {
		ans = ans + s;
		s++;
	}
	printf("%d", s - 1);

	return 0;
}