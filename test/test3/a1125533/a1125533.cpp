#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<deque>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cctype>
#include<iterator>
#include<list>
#include<queue>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;
		num[i] = a;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (num[i] > num[j])
			{
				int tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}
	int search;
	while (cin >> search)
	{
		bool flag = 1;
		int min = 0, max = n - 1, mid;
		while (max >= min)
		{
			int c = 0;
			mid = (min + max)  / 2;
			c = num[mid];
			if (c > search)
			{
				max = mid - 1;
				flag = 0;
			}
			else if (c < search)
			{
				min = mid + 1;
				flag = 0;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			cout << search << " found" << endl;
		else
			cout << search << " not found" << endl;
	}
	return 0;
}