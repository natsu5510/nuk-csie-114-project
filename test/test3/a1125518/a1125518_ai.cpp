#include <stdio.h>


int findGroupSize(int S, int D) {
    int daysPassed = 0;  // �g�L���`�Ѽ�
    int currentGroupSize = S;  // ��e�Ȧ�Ϊ��H��

    // ����W�[�Ѽƪ���F��ζW�L���w���Ѽ�D
    while(daysPassed < D) {
        daysPassed += currentGroupSize;  // �W�[��e�Ȧ�Ϊ����d�Ѽ�
        if(daysPassed < D) {
            currentGroupSize++;  // �p�G�٨S��F��D�ѡA�U�@�ήȦ�Ϊ��H�Ʒ|�[�@
        }
    }

    return currentGroupSize;  // ��^�b��D�ѤJ���Ȧ�Ϊ��H��
}

int main() {
    int S, D;

    // �ϥΪ̿�J

    scanf("%d %d", &S, &D);

    // �p��ÿ�X���G
    printf("%d\n", findGroupSize(S, D));

    return 0;
}
