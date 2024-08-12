#include "iostream"
#include "vector"

using namespace std;

int min(int a, int b) {
    if (a < b) return a;
    
    return b;
}

int uglyNumber(int n) {
    int i, idx2 = 0, idx3 = 0, idx5 = 0;
    int ugly2 = 2, ugly3 = 3, ugly5 = 5, ugly_num = 1;
    vector<int> v;
    v.push_back(ugly_num);

    for (i = 1;i<n;i++) {
        ugly_num = min(min(ugly2, ugly3), ugly5);
        v.push_back(ugly_num);
        if (ugly_num == ugly2) {
            ugly2 = v[++idx2] * 2;
        }
        if (ugly_num == ugly3) {
            ugly3 = v[++idx3] * 3;
        }
        if (ugly_num == ugly5) {
            ugly5 = v[++idx5] * 5;
        }
    }
    
    return v.back();
}

int main() {
    int n;
    cin >> n;
    cout << uglyNumber(n);

    return 0;
}