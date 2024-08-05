#include <stdio.h>
#include <math.h>

int main() {
    // �ŧi�ܼ�
    int S, D, start, end, low, high, mid, test_start, test_end, ans;

    // �ΰj��Ū����J�A����J��EOF
    while (scanf("%d %d", &S, &D) != EOF) {
        // �p��Ĥ@�ծȦ�Ϊ��J��M�h�Ф��
        start = 1;
        end = S;

        // �ΤG���k���b��D�ѤJ���Ȧ�ΤH��
        low = S;
        high = 10000;
        ans = -1;
        while (low <= high) {
            // �������ȧ@�����ժ��Ȧ�ΤH��
            mid = (low + high) / 2;

            // �p����ժ��Ȧ�Ϊ��J��M�h�Ф��
            test_start = start + (mid - S) * (mid + S + 1) / 2;
            test_end = test_start + mid - 1;

            // �P�_�O�_�ŦX����
            if (test_start <= D && test_end >= D) {
                // ���F����
                ans = mid;
                break;
            }
            else if (test_start > D) {
                // ���ժ��Ȧ�ΤH�ƤӦh�A�ݭn���
                high = mid - 1;
            }
            else {
                // ���ժ��Ȧ�ΤH�ƤӤ֡A�ݭn�W�[
                low = mid + 1;
            }
        }

        // ��X����
        printf("%d\n", ans);
    }

    return 0;
}