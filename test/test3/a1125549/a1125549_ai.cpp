#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)

// 這個函數計算在第 D 天入住的旅行團人數
int find_group(int S, long long D) {
	// 用二分法找到最大的 k，使得 k * (k + 1) / 2 + S * k <= D
	// 這表示有 k 個旅行團已經入住並退房
	int low = 0, high = (int)sqrt(2 * D);
	int k = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		long long sum = mid * (mid + 1LL) / 2 + S * mid;
		if (sum <= D) {
			k = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	// 如果 D 剛好等於最後一個旅行團退房的日期，則返回 0
	if (D == k * (k + 1LL) / 2 + S * k) {
		return 0;
	}
	// 否則，返回下一個旅行團的人數，即 S + k + 1
	return S + k + 1;
}

int main() {
	int S; // 第一組旅行團人數
	long long D; // 要查找的日期
	while (scanf("%d %lld", &S, &D) == 2) { // 讀取輸入，直到沒有更多數據
		int ans = find_group(S, D); // 計算答案
		printf("%d\n", ans); // 輸出答案
	}
	return 0;
}