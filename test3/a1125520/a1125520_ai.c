#include <stdio.h>
#include <math.h>

int main() {
    long long S, D;
    while (scanf("%lld %lld", &S, &D) == 2) {
        // 計算入住旅行團人數的公式
        long long f = (2 * D) + (S * S) - S;
        // 使用一元二次方程式求解入住旅行團人數
        double ans = (-1 + sqrt(1 - 4 * (-f))) / 2;
        // 輸出在第D天入住的旅行團人數
        printf("%lld\n", (long long)ceil(ans));
    }
    return 0;
}
