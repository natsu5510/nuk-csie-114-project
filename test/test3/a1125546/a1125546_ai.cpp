#include <stdio.h>
#pragma warning(disable:4996)

int main() {
    int S; // �Ĥ@�ծȦ�ΤH��
    long long D; // �n�d�䪺�J��Ѽ�

    while (scanf("%d %lld", &S, &D) == 2) {
        long long currentDay = 1; // ��e�Ѽ�
        long long currentGroupSize = S; // ��e�Ȧ�ΤH��

        while (D > currentDay) {
            currentDay += currentGroupSize; // ��s��e�Ѽ�
            currentGroupSize++; // ��s��e�Ȧ�ΤH��
        }

        printf("%lld\n", currentGroupSize - 1); // ��X�b��D�ѤJ���Ȧ�ΤH��
    }

    return 0;
}