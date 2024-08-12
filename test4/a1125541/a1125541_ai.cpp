#include <stdio.h>
#include <stdbool.h>

// �P�_�@�ӼƬO�_�� Ugly Number
bool is_ugly(int n) {
	// �p�G n �� 0 �έt�ơA�h���O Ugly Number
	if (n <= 0) {
		return false;
	}
	// �p�G n �� 1�A�h�O Ugly Number
	if (n == 1) {
		return true;
	}
	// �p�G n �i�H�Q 2, 3 �� 5 �㰣�A�h���H�Ӧ]�ơA���~��P�_
	if (n % 2 == 0) {
		return is_ugly(n / 2);
	}
	if (n % 3 == 0) {
		return is_ugly(n / 3);
	}
	if (n % 5 == 0) {
		return is_ugly(n / 5);
	}
	// �p�G n ����Q 2, 3 �� 5 �㰣�A�h���O Ugly Number
	return false;
}

// �D�X�� N �� Ugly Number
int nth_ugly(int n) {
	// �p�G n �� 0 �έt�ơA�h��^ -1 ��ܿ��~
	if (n <= 0) {
		return -1;
	}
	// �]�w�@�ӭp�ƾ��A�q 1 �}�l
	int count = 1;
	// �]�w�@���ܼơA�q 1 �}�l�A�ΨӹM���Ҧ�����
	int num = 1;
	// ��p�ƾ��p�� n �ɡA�~��`��
	while (count < n) {
		// �N num �[�@
		num++;
		// �p�G num �O Ugly Number�A�h�N�p�ƾ��[�@
		if (is_ugly(num)) {
			count++;
		}
	}
	// ��^ num�A�Y�� N �� Ugly Number
	return num;
}

int main() {
	// ��J�@�ӥ���� N
	int N;
	printf("�п�J�@�ӥ���� N�G");
	scanf("%d", &N);
	// ��X�� N �� Ugly Number
	printf("�� %d �� Ugly Number �O %d\n", N, nth_ugly(N));
	return 0;
}
