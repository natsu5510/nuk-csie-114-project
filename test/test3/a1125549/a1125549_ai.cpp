#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)

// �o�Ө�ƭp��b�� D �ѤJ���Ȧ�ΤH��
int find_group(int S, long long D) {
	// �ΤG���k���̤j�� k�A�ϱo k * (k + 1) / 2 + S * k <= D
	// �o��ܦ� k �ӮȦ�Τw�g�J��ðh��
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
	// �p�G D ��n����̫�@�ӮȦ�ΰh�Ъ�����A�h��^ 0
	if (D == k * (k + 1LL) / 2 + S * k) {
		return 0;
	}
	// �_�h�A��^�U�@�ӮȦ�Ϊ��H�ơA�Y S + k + 1
	return S + k + 1;
}

int main() {
	int S; // �Ĥ@�ծȦ�ΤH��
	long long D; // �n�d�䪺���
	while (scanf("%d %lld", &S, &D) == 2) { // Ū����J�A����S����h�ƾ�
		int ans = find_group(S, D); // �p�⵪��
		printf("%d\n", ans); // ��X����
	}
	return 0;
}