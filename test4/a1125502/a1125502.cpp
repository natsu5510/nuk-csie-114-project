#include <stdio.h>
#include <stdlib.h>

int findUglyNumber(int n) {
    int* uglyNumbers = (int*)malloc(n * sizeof(int)); // �ϥΰʺA�t�m�O����
    if (!uglyNumbers) {
        fprintf(stderr, "�O����t�m����\n");
        exit(EXIT_FAILURE);
    }

    int i2 = 0, i3 = 0, i5 = 0;
    uglyNumbers[0] = 1;

    for (int i = 1; i < n; i++) {
        int nextUgly = (uglyNumbers[i2] * 2 < uglyNumbers[i3] * 3) ? uglyNumbers[i2] * 2 : uglyNumbers[i3] * 3;
        nextUgly = (nextUgly < uglyNumbers[i5] * 5) ? nextUgly : uglyNumbers[i5] * 5;

        if (nextUgly == uglyNumbers[i2] * 2) i2++;
        if (nextUgly == uglyNumbers[i3] * 3) i3++;
        if (nextUgly == uglyNumbers[i5] * 5) i5++;

        uglyNumbers[i] = nextUgly;
    }

    int result = uglyNumbers[n - 1];
    free(uglyNumbers); // ����ʺA�t�m���O����
    return result;
}

int main() {
    int N;
    printf("");
    scanf_s("%d", &N);

    printf("%d\n", findUglyNumber(N));

    return 0;
}

