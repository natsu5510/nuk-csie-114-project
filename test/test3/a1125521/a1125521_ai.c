#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int S;  // 第一组旅行团人数
    long long D;  // 要查找的天数

    while (scanf("%d %lld", &S, &D) == 2) {
        long long current_day = 1;  // 当前天数
        int current_group_size = S;  // 当前旅行团人数

        while (D > current_day + current_group_size - 1) {
            current_day += current_group_size;
            current_group_size++;
        }

        printf("%d\n", current_group_size);
    }

    return 0;
}

