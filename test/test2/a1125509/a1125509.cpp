#include<iostream>
using namespace std;
int main()
{
	int n;
	int j = 0;
	int i = 1;
	while (cin >> n) {
		while (n <= 2023) {

			if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
			{j++;}
			n++;
			if (j = n)
			{cout << i << endl;}
		}
		}
}