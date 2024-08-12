#include <stdio.h>

int findGroupSize(int S, long long D) {
    long long day = 1;
    int groupSize = S;
    while (day < D) {
        groupSize++;
        day += groupSize;
    }
    return groupSize;
}

int main() {
    int S;
    long long D;
    printf("請輸入第一組旅行團人數S：");
    scanf("%d", &S);
    printf("請輸入要查詢的天數D：");
    scanf("%lld", &D);
    int result = findGroupSize(S, D);
    printf("在第%lld天入住的旅行團人數為：%d\n", D, result);
    return 0;
}