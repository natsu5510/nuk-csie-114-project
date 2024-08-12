#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	double s, d;
	while (scanf("%d %d", &s, &d) != EOF)
	{
		while (d > 0 && d > s)
		{
			d -= s;
			s++;
		}
		printf("%d\n", s);
	}
}