#include <stdio.h>

int main() {
    int S;  // �Ĥ@�ծȦ�ΤH��
    long long D;  // ��D��

    while (scanf("%d %lld", &S, &D) == 2) {
        long long current_day = 1;
        int current_group_size = S;

        while (D > current_day) {
            current_day += current_group_size;
            current_group_size++;
        }

        printf("%d\n", current_group_size - 1);
    }

    return 0;
}
