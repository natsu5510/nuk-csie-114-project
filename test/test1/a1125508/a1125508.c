// Online C compiler to run C program online
#include <stdio.h>

int main() {
	int s, d, k;
	k = 0;
	scanf("%d %d", &s, &d);
	while (s < d){
		k = k + s;
		s = s + 1;
	}
	printf("%d", k);
	return 0;
}