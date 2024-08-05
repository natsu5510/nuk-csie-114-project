#include <stdio.h>

int main() {
	int S, D, st = 1;
	scanf("%d", &S);
	scanf("%d", &D);
	if (S >= 1 && S <= 10000 && D >= 1 && (D <= (10 ^ 15))) {
		for (st < D;) {
			st = st + S - 1;
			S = S + 1;
		}
	}
	else {
		return 0;
	}
	printf("%d\n", S);
	return 0;
}