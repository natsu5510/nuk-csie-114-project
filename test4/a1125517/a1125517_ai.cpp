#include<bits/stdc++.h>
using namespace std;

#define MAXN 2023

long long ugly[MAXN];

void generateUglyNumbers() {
    ugly[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    for(int i = 1; i < MAXN; i++) {
        ugly[i] = min({2*ugly[i2], 3*ugly[i3], 5*ugly[i5]});
        if(ugly[i] == 2*ugly[i2]) i2++;
        if(ugly[i] == 3*ugly[i3]) i3++;
        if(ugly[i] == 5*ugly[i5]) i5++;
    }
}

int main() {
    generateUglyNumbers();
    int N;
    while(cin >> N) {
        if(N <= 0 || N > MAXN) {
            cout << "輸入的N超出範圍，請輸入1到" << MAXN << "之間的數字。" << endl;
            continue;
        }
        cout << ugly[N-1] << endl;
    }
    return 0;
}
