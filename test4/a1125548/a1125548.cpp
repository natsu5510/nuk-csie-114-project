#include <stdio.h>
#include<string.h>

int count = 0;
void find(long long int nums[], int n) {
    long long int t = nums[count];
    while (count != n - 1) {
        t++;
        long long int ans = t;
        while (t % 2 == 0) {
            t = t / 2;
        }
        while (t % 3 == 0) {
            t = t / 3;
        }
        while (t % 5 == 0) {
            t = t / 5;
        }
        if (t == 1) {
            count++;
            nums[count] = ans;
        }
        t = ans;
    }

}

int main(void) {
    long long int nums[2023];
    nums[0] = 1;
    int n;
    long long int ans;
    while (scanf("%d", &n)) {
        if (count >= n - 1) {
            printf("%lld\n", nums[n - 1]);
        }
        else {
            find(nums, n);
            printf("%lld\n", nums[n - 1]);
        }
    }
    return 0;
}