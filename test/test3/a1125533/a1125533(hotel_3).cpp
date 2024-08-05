#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<ctype.h>
#include<string.h>
#include<string>

using namespace std;

int main()
{
	long long d = 0;
	int s = 0;
	while (cin >> s >> d)
	{
		while (d > 0 && d > s)
		{
			d -= s;
			s++;
		}
		cout << s << endl;
	}
	return 0;
}
/*int main()
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