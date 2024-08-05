#include <stdio.h>
#pragma warning (disable:4996)
int main()
{
	int s, d;
	while (scanf("%d %d", &s, &d) != EOF)
	{
		while (d>0)
		{
			d = d - s;
			s++;
		}
		printf("%d\n", s-1);
	}
}