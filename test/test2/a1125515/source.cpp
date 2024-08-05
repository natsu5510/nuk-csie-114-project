#include <bits/stdc++.h>
using namespace std;
#define k 100000
int q, z, s, x, e, d, c, r, f, v, t;
string g, b;
long long w, a, y[k];
int main() {
  while (cin >> q) {
    while (q > z) {
      w += 1;
      a = w;
      while (1) {
        if (a == 1) {
          y[z] = w;
          z += 1;
          break;
        }
        if (a % 2 == 0) {
          a /= 2;
        } else if (a % 3 == 0) {
          a /= 3;
        } else if (a % 5 == 0) {
          a /= 5;
        } else {
          break;
        }
      }
    }
    cout << y[q - 1] << "\n";
  }
}
