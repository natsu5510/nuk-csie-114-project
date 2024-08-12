#include <stdio.h>

long long calculate_group_size(long long S, long long D) {
    long long days = 1;
    while (days * (days + 1) / 2 < D) {
        S++;
        days++;
    }
    return S;
}

int main() {
    long long S, D;
    printf("�п�J�Ĥ@�ΤH�ƩM�d�䪺�ѼơG\n");
    scanf("%lld %lld", &S, &D);
    printf("�� %lld �ѮȦ�Ϊ��H�Ƭ��G %lld\n", D, calculate_group_size(S, D));
    return 0;
}
