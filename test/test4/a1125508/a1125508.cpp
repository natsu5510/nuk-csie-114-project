#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)
void bsort(float a[9999], int l) {
	int i, j;
	double temp;
	for (i = 0; i < l; i++) {
		for (j = 0; j < l - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	
}
float uglynumber(int k) {
	int a, b, c, i = 0;
	float uglnum[9999];
	for (c = 0; c < 10; c++) {
		for (b = 0; b < 15; b++) {
			for (a = 0; a < 20; a++) {
				uglnum[i] = pow(2.0, a) * pow(3.0, b) * pow(5.0, c);
				i++;
			}
		}
	}
	bsort(uglnum, 3000);
	return uglnum[k - 1];
}
int main() {
	int k;
	while (scanf("%d", &k) != EOF) {
		printf("%.0f\n", uglynumber(k));
	}
}