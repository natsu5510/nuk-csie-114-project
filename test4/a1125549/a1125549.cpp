#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		int counter = 0;
		long long int i;
		for (i = 1; counter<N; i++)
		{
			long long int temp = i;
			while (temp / 2 != 0 && temp % 2 == 0)
				temp = temp / 2;
			if (temp == 1)
				counter++;
			else
			{
				while (temp / 3 != 0 && temp % 3 == 0)
					temp = temp / 3;
				if (temp == 1)
					counter++;
				else 
				{
					while (temp / 5 != 0 && temp % 5 == 0)
						temp = temp / 5;
					if (temp == 1)
						counter++;
				}
			}
		}
		printf("%lld\n", i-1);
	}
}