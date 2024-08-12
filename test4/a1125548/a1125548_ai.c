
#include <stdio.h>

int maxDivide(int a, int b) {
    while (a % b == 0) {
        a = a / b;
    }
    return a;
}

int isUgly(int num) {
    num = maxDivide(num, 2);
    num = maxDivide(num, 3);
    num = maxDivide(num, 5);
    return (num == 1) ? 1 : 0;
}

int getUglyNumber(int n) {
    int i = 1;
    int count = 1;
    while (n > count) {
        i++;
        if (isUgly(i)) {
            count++;
        }
    }
    return i;
}

int main() {
    int n ;
    while(scanf("%d", &n)){
        printf("%d\n", getUglyNumber(n));
        return 0;
    }
}
