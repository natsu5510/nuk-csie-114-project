#include <stdio.h>

long long calculate_group_size(long long S, long long D) {
    long long days = 1;
    while (days * (days + 1) / 2 < D) {
        S++;
        days++;
    }
    return S;
}

int main() {
    long long S, D;
    printf("請輸入第一團人數和查找的天數：\n");
    scanf("%lld %lld", &S, &D);
    printf("第 %lld 天旅行團的人數為： %lld\n", D, calculate_group_size(S, D));
    return 0;
}
