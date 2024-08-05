#include <stdio.h>
#include <stdbool.h>

// 判斷一個數是否為 Ugly Number
bool is_ugly(int n) {
	// 如果 n 為 0 或負數，則不是 Ugly Number
	if (n <= 0) {
		return false;
	}
	// 如果 n 為 1，則是 Ugly Number
	if (n == 1) {
		return true;
	}
	// 如果 n 可以被 2, 3 或 5 整除，則除以該因數，並繼續判斷
	if (n % 2 == 0) {
		return is_ugly(n / 2);
	}
	if (n % 3 == 0) {
		return is_ugly(n / 3);
	}
	if (n % 5 == 0) {
		return is_ugly(n / 5);
	}
	// 如果 n 不能被 2, 3 或 5 整除，則不是 Ugly Number
	return false;
}

// 求出第 N 個 Ugly Number
int nth_ugly(int n) {
	// 如果 n 為 0 或負數，則返回 -1 表示錯誤
	if (n <= 0) {
		return -1;
	}
	// 設定一個計數器，從 1 開始
	int count = 1;
	// 設定一個變數，從 1 開始，用來遍歷所有的數
	int num = 1;
	// 當計數器小於 n 時，繼續循環
	while (count < n) {
		// 將 num 加一
		num++;
		// 如果 num 是 Ugly Number，則將計數器加一
		if (is_ugly(num)) {
			count++;
		}
	}
	// 返回 num，即第 N 個 Ugly Number
	return num;
}

int main() {
	// 輸入一個正整數 N
	int N;
	printf("請輸入一個正整數 N：");
	scanf("%d", &N);
	// 輸出第 N 個 Ugly Number
	printf("第 %d 個 Ugly Number 是 %d\n", N, nth_ugly(N));
	return 0;
}
