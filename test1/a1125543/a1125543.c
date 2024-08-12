#include<stdio.h>
#pragma warning (disable:4996)

int main()
{
	int S = 0, D = 0;
	scanf("%d %d", &S,&D);
	while (D > S)
	{
		D = D - S;
		S = S + 1;
	}
	printf("%d", S);

	return 0;
}