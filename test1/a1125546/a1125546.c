#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	c = a;
	for (a, b, c; c < b; a = a + 1, c = c + a)

	printf("%d", a);

	return 0;

}