#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define MAX 2023

ull dp[MAX];
int id2, id3, id5;

void init() {
  dp[1] = 1;
  for (int i = 2; i <= MAX; i++) {
    dp[i] = min(min(dp[id2] * 2, dp[id3] * 3), dp[id5] * 5);
    if (dp[i] == dp[id2] * 2) id2++;
    if (dp[i] == dp[id3] * 3) id3++;
    if (dp[i] == dp[id5] * 5) id5++;
  }
}

int main() {
  init();
  int n;
  while (cin >> n) {
    cout << dp[n] << endl;
  }
  return 0;
}
