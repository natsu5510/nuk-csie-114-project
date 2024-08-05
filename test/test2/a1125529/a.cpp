// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int maxDivide(int a, int b)
{
	while (a%b == 0);
	a = a / b;
	return a;
}

int ugly(int no) {
	no = maxDivide(no, 2);
	no = maxDivide(no, 3);
	no = maxDivide(no, 5);

	return (no == 1) ? 1 : 0;
}

int getnougly(int n)
{
	int i = 1;
	int count = 1;
	while (n > count) {
		i++;
		if (ugly(i))
			count++;
	}
	return i;
}

int main()
{
	int n;
	scanf("%d", &n);
	unsigned no = getnougly(n);
	printf("%d", no);
	getchar();
	return 0;
}