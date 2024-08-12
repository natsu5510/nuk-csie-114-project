#include <stdio.h>

unsigned getNthUglyNo(unsigned n) {
    unsigned ugly[n]; // To store ugly numbers
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;

    ugly[0] = 1;
    for (int i = 1; i < n; i++) {
       next_ugly_no = (next_multiple_of_2 < next_multiple_of_3) ?
                       next_multiple_of_2 : next_multiple_of_3;
       next_ugly_no = (next_ugly_no < next_multiple_of_5) ?
                       next_ugly_no : next_multiple_of_5;

       ugly[i] = next_ugly_no;
       if (next_ugly_no == next_multiple_of_2) {
           i2 = i2 + 1;
           next_multiple_of_2 = ugly[i2] * 2;
       }
       if (next_ugly_no == next_multiple_of_3) {
           i3 = i3 + 1;
           next_multiple_of_3 = ugly[i3] * 3;
       }
       if (next_ugly_no == next_multiple_of_5) {
           i5 = i5 + 1;
           next_multiple_of_5 = ugly[i5] * 5;
       }
    }
    return next_ugly_no;
}

int main() {
    unsigned n;
    printf("Enter the value of n to get nth ugly number: ");
    scanf("%u", &n);
    printf("The %uth ugly number is %u.\n", n, getNthUglyNo(n));
    return 0;
}
