#include <iostream>
using namespace std;

    int NUglyNumber(int n) 
    {
        int next_multiple_of_2 = i2, next_multiple_of_3 = i3, next_multiple_of_5 = i5;

        for (int i = 1; i < n; i++) 
        {
            if (next_ugly == next_multiple_of_2) 
            {
                i2++;
                next_multiple_of_2 = ugly[i2] * 2;
            }
            if (next_ugly == next_multiple_of_3) 
            {
                i3++;
                next_multiple_of_3 = ugly[i3] * 3;
            }
            if (next_ugly == next_multiple_of_5) 
            {
                i5++;
                next_multiple_of_5 = ugly[i5] * 5;
            }
        }

        return ugly[n - 1];
    }

    int main()
    {
        int N;
        cout << "請輸入要找的第 N 個 Ugly Number（1 <= N <= 2023）: ";
        cin >> N;   

        if (N < 1 || N > 2023) 
        {
            cout << "輸入無效。";
        }
        else 
        {
            int result = NUglyNumber(N); 
            cout << "第 " << N << " 個 Ugly Number 是: "<< result << endl;
        }

        return 0;
    }