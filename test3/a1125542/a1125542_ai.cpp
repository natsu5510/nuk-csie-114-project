#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int s, d;

	//���y�Τ��J����ӼƦr
	printf("�п�J��ӼƦr�A�H�Ů����: ");
	scanf("%d %d", &s, &d);

	int count = 0;//������e�Ʀr���Ӽ�
	int currentNumber = s;//��e��X���Ʀr

	//�}�l��J�ŦX�W�h���Ʀr
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