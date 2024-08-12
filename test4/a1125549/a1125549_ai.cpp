#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#pragma warning(disable:4996)

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
    // ���_���H 2, 3, 5�A����L�k�㰣�ά� 1
    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    while (n % 5 == 0) {
        n /= 5;
    }
    // �p�G�̫� n �� 1�A�h�O Ugly Number�A�_�h���O
    return n == 1;
}

// �D�X�� n �� Ugly Number
int nth_ugly(int n) {
    // �p�G n �� 0 �έt�ơA�h��^ -1 ��ܿ��~
    if (n <= 0) {
        return -1;
    }
    // �Τ@���ܼ� i �ӰO����e���ơA�Τ@���ܼ� count �ӰO���w�g��쪺 Ugly Number ���Ӽ�
    int i = 1, count = 0;
    // �� count �p�� n �ɡA���_�W�[ i �çP�_�O�_�� Ugly Number
    while (count < n) {
        if (is_ugly(i)) {
            // �p�G�O Ugly Number�A�h count �[�@
            count++;
        }
        // i �[�@
        i++;
    }
    // ��^ i - 1�A�Y�� n �� Ugly Number
    return i - 1;
}

// �D���
int main() {
    // �w�q�@���ܼ� n �Ӧs�x��J����
    int n;
    // �Τ@�Ӱj���Ū����J�A����J�� EOF
    while (scanf("%d", &n) != EOF) {
        // �ե� nth_ugly ��ƨӨD�X�� n �� Ugly Number
        int ans = nth_ugly(n);
        // ��X���סA�榡�� "�� n �� Ugly Number �� ans"
        printf("�� %d �� Ugly Number �� %d\n", n, ans);
    }
    // ��^ 0 ��ܥ��`����
    return 0;
}