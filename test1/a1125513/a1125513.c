#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c, i, d, x;
	c = 0;
	x = 0;
	scanf("%d %d", &a, &b);

	for (i = a; i < (b + 1); i++)
	{
		for (d = 1; d < (i + 1); d++)
		{
			c += 1;
			if (c == b);
			{
				printf("%d", i + 2);
				x = 1;
			}

			if (x)
				break;
		}
		if (x)
			break;
	}




}