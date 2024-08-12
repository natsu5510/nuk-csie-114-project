#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int n=0;
	while (scanf("%d", &n)) {
		int ugly = 1, numf = 1;
		for (ugly = 1; ugly <= n; ugly++) {
			numf = numf + 1;
			while(true){
				int numb = numf;
				if (numb % 2 == 0) numb = numb / 2;
				else if (numb % 3 == 0) numb = numb / 3;
				else if (numb % 5 == 0) numb = numb / 5;
				if (numb == 1) break;
			}
		}
		printf("%d\n", numf);
	}
	return 0;
}