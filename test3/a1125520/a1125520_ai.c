#include <stdio.h>
#include <math.h>

int main() {
    long long S, D;
    while (scanf("%lld %lld", &S, &D) == 2) {
        // �p��J��Ȧ�ΤH�ƪ�����
        long long f = (2 * D) + (S * S) - S;
        // �ϥΤ@���G����{���D�ѤJ��Ȧ�ΤH��
        double ans = (-1 + sqrt(1 - 4 * (-f))) / 2;
        // ��X�b��D�ѤJ���Ȧ�ΤH��
        printf("%lld\n", (long long)ceil(ans));
    }
    return 0;
}
