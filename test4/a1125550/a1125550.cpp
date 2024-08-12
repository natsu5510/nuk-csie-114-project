#include<stdio.h>
#pragma warning (disable:4996)

int main() {
	long long int n;
	scanf("%lld", &n);
	int count = 0;
	int answer = 1;
	int a;
	while (count<1000){
		a = answer;
		while (a % 2 == 0) {
			a /= 2;
		}
		while (a % 3 == 0) {
			a /= 3;
		}
		while (a % 5 == 0) {
			a /= 5;
		}
		if (a == 1) {
			count++;
			if (count == n) {
				printf("%d\n", answer);
				break;
			}
		}
		answer++;
	}
	return 0;
}