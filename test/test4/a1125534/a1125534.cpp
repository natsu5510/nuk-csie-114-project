# include <stdio.h>
# pragma warning (disable:4996)

int main() {

	int n;
	while (scanf("%d", &n) != EOF) {

		int i = 1;
		int sum = 0;
		int k;

		while (sum <= n) {

			int k = i;

			while (k % 2 == 0) {
				k /= 2;
			}

			while (k % 3 == 0) {
				k /= 3;
			}

			while (k % 5 == 0) {
				k /= 5;
			}

			if (k == 1) {
				sum++;
			}

			if (sum == n) {
				printf("%d\n", i);
				break;
			}

			i++;
		}

	}
}

