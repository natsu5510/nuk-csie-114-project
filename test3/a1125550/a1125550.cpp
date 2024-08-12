#include<stdio.h>
#pragma warning (disable:4996)

int main() {
	int s;
	int d;
	scanf("%d %d", &s,&d);
	int temp;
	for (int i = 0; i < d; i++){
		s+=i;
		if (s >= d) {
			temp = i;
			break;
		}
		else {
			continue;
		}
	}
	printf("%d", temp);
	return 0;
}