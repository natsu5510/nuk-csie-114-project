#include <stdio.h>


int main(void)
{
	int S;
	int D;
	int sum=0;
	scanf_s("%d", &S);
	scanf_s("%d", &D);
	while (S >= 1 && S <= 10000&&D>=1&&D<=10^15&&S<=D&&sum<=D) {
		sum = sum + S;
		S = S + 1;
		
	}
	printf("%d", S);
}
