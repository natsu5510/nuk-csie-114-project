#include <stdio.h>

int find_group(int S, int D) {
	int cumulative_days = S;
	int group_size = S;

	while (cumulative_days < D) {
		group_size += 1;
		cumulative_days += group_size;
	}

	return group_size;
}

int main() {
	int S, D;

	// 輸入 S 和 D 的值
	printf("Enter the value of S: ");
	scanf_s("%d", &S);

	printf("Enter the value of D: ");
	scanf_s("%d", &D);

	// 呼叫函式並輸出結果
	int result = find_group(S, D);
	printf("The minimum group size is: %d\n", result);

	return 0;
}
