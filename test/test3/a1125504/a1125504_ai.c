#include <stdio.h>

long long findGroupSize(long long S, long long D) {
    long long currentGroup = S; // 初始化当前团队人数为初始团队人数
    long long dayCount = 0; // 初始化天数计数器

    while (dayCount < D) {
        dayCount += currentGroup; // 累加当前团队停留的天数
        currentGroup++; // 下一团队人数比当前团队多1
    }

    return currentGroup - 1; // 因为超出D天停留，所以需要减去1
}

int main() {
    long long S, D;
    while (scanf("%lld %lld", &S, &D) == 2) {
        long long result = findGroupSize(S, D);
        printf("%lld\n", result);
    }
    return 0;
}
