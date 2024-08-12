#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

unsigned long long int ugly[2024];

void uglynum()
{
	ugly[1] = 1;
	int p2 = 1, p3 = 1, p5 = 1;
	for (int n = 2; n <= 2023; n++)
	{
		while (ugly[p2] * 2 <= ugly[n - 1]) p2++;
		while (ugly[p3] * 3 <= ugly[n - 1]) p3++;
		while (ugly[p5] * 5 <= ugly[n - 1]) p5++;
		ugly[n] = min({ugly[p2] * 2, ugly[p3] * 3, ugly[p5] * 5});
	}
}
int main()
{
	int n;
	uglynum();
	while (cin >> n, n)
	{
		cout << ugly[n]<<endl;
	}
	return 0;
}

/*
int main()
{
	char x[] = "it is a beautiful day outside";
	char y[] = "birds are singing and flowers are blooming";
	char z[] = "but one day, I met a kid";
	char a[] = "kid like you";
	char b[] = "should be burn in the hell";
	char* p = strtok(b, " ");//將char b 變成should\nbe burn in the hell
	while (p != NULL)
	{
		cout << p << endl;
		p = strtok(NULL, " ");//找到NULL之後到delimiters(這邊是space)分割NULL到space之間的字串，若是第二次token -> should\nbe\nburn in the hell(這時的p來到了be\nburn 的\n)
	}
	cout << (char*)memmove(x, &x[18], 11) << endl;//將原本的char x前11個自被從原char x[18]開始算起的11個字覆蓋再將char x[11以後的字串輸出]
	cout << memcmp(x, y, 1) << endl;//從字串[0]開始的 third parameter個字比較 first param >= second param ?
}*/