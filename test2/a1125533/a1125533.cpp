// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include<iostream>

bool isugly(long long int);
using namespace std;
int main()
{
	int num = 0;
	while (cin >> num)
	{
		long long int temp = 2;
		num--;
		while (num > 0)
		{
			if (!isugly(temp))
				temp++;
			else
			{
				num--;
				temp++;
			}
		}
		temp--;
		cout << temp << endl;
	}
	return 0;
}
bool isugly(long long int a)
{
	bool flag = true;
	while (a > 1)
	{
		if (a % 2 == 0)
			a /= 2;
		else if (a % 3 == 0)
			a /= 3;
		else if (a % 5 == 0)
			a /= 5;
		else
		{
			flag = false;
			break;
		}
	}
	return flag;
}
