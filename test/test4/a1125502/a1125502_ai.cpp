#include<stdio.h>

#define MAX_N 2024

unsigned uglyNumber[MAX_N];

unsigned min(unsigned a, unsigned b, unsigned c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

void generateUglyNumbers() {
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;

    uglyNumber[0] = 1;

    for (int i = 1; i < MAX_N; i++) {
        next_ugly_no = min(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5);
        uglyNumber[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2) {
            i2 = i2 + 1;
            next_multiple_of_2 = uglyNumber[i2] * 2;
        }
        if (next_ugly_no == next_multiple_of_3) {
            i3 = i3 + 1;
            next_multiple_of_3 = uglyNumber[i3] * 3;
        }
        if (next_ugly_no == next_multiple_of_5) {
            i5 = i5 + 1;
            next_multiple_of_5 = uglyNumber[i5] * 5;
        }
    }
}

int main() {
    generateUglyNumbers();
    unsigned N;
    printf("Enter the Nth number to find the Nth Ugly Number: ");
    scanf_s("%u", &N);
    if (N >= 1 && N <= 2023) {
        printf("The %uth Ugly Number is: %u\n", N, uglyNumber[N - 1]);
    }
    else {
        printf("Invalid input. Please enter a number between 1 and 2023.\n");
    }
    return 0;
}
