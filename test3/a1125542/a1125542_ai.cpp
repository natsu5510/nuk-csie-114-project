#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int s, d;

	//掃描用戶輸入的兩個數字
	printf("請輸入兩個數字，以空格分離: ");
	scanf("%d %d", &s, &d);

	int count = 0;//紀錄當前數字的個數
	int currentNumber = s;//當前輸出的數字

	//開始輸入符合規則的數字
	while (count < d) {
		for (int i = 0; i < currentNumber; i++) {
			count++;
			if (count == d) {
				printf("%d\n", currentNumber);
				break;
			}
		}
		currentNumber++;
	}
	return 0;
}