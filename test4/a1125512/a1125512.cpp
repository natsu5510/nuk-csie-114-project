#include <bits/stdc++.h>
using namespace std;

int getuglynumber(int n) {
    if (n <= 0) return 0;

    vector<int> uglynumbers(n, 0);
    uglynumbers[0] = 1;
    int n2 = 2, n3 = 3, n5 = 5;
    int index2 = 0, index3 = 0, index5 = 0;
    int nextugly;

    for (int i = 1; i < n; i++) { 
        nextugly = min(n2, min(n3, n5));
        uglynumbers[i] = nextugly;

        if (nextugly == n2) {
            index2++;
            n2 = uglynumbers[index2] * 2;
        }
        if (nextugly == n3) {
            index3++;
            n3 = uglynumbers[index3] * 3;
        }
        if (nextugly == n5) {
            index5++;
            n5 = uglynumbers[index5] * 5;
        }
    }

    return uglynumbers[n - 1];
}

int main() {
    int n;
    cin >> n;
    cout << getuglynumber(n) << endl;
    return 0;
}