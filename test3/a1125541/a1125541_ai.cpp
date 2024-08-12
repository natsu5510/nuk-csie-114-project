#include <stdio.h>
#include <math.h>

int main() {
    // 宣告變數
    int S, D, start, end, low, high, mid, test_start, test_end, ans;

    // 用迴圈讀取輸入，直到遇到EOF
    while (scanf("%d %d", &S, &D) != EOF) {
        // 計算第一組旅行團的入住和退房日期
        start = 1;
        end = S;

        // 用二分法找到在第D天入住的旅行團人數
        low = S;
        high = 10000;
        ans = -1;
        while (low <= high) {
            // 取中間值作為測試的旅行團人數
            mid = (low + high) / 2;

            // 計算測試的旅行團的入住和退房日期
            test_start = start + (mid - S) * (mid + S + 1) / 2;
            test_end = test_start + mid - 1;

            // 判斷是否符合條件
            if (test_start <= D && test_end >= D) {
                // 找到了答案
                ans = mid;
                break;
            }
            else if (test_start > D) {
                // 測試的旅行團人數太多，需要減少
                high = mid - 1;
            }
            else {
                // 測試的旅行團人數太少，需要增加
                low = mid + 1;
            }
        }

        // 輸出答案
        printf("%d\n", ans);
    }

    return 0;
}