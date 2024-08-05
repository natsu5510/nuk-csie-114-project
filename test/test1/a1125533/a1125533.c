#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b;
	a = b = 0;
	int temp = 0;;//give a temporary varity for a to calculate how many people live in the hotel with the corresponding day, and not to change the variable of a
	scanf("%d%d", &a, &b);
	temp = a;
	for (int i = 0; i < b; i++)
	{
		if (temp == 0)//while the day count to 0 , another gropu with one more person than the previous group will live in, and live with a+1 day
		{
			a++;//how many peoploe in the group in corresponding day
			temp = a + 1;//not to change the variable of a, add one more 1 is because temp will minus one in the next command so the day the group stay will not  loss 1
		}
		temp--;//count down the day
	}
	printf("%d", a);
}