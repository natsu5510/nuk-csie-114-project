#include <stdio.h>

int find_group(int s, long long d) {
  if (d <= s) {
    return s;
  }
  int low = s;
  int high = 10000;
  while (low < high) {
    int mid = (low + high) / 2;
    long long days = (long long)(s + mid) * (mid - s + 1) / 2;
    if (days < d) {
      low = mid + 1;
    }
    else {
      high = mid;
    }
  }
  return low;
}

int main() {
  int s;
  long long d;
  scanf("%d %lld", &s, &d);
  int ans = find_group(s, d);
  printf("%d\n", ans);
  return 0;
}
