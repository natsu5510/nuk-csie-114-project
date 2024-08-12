#include <stdio.h>
int main()
{
    int n, i,sum, day;
    while (scanf("%d %d", &n, &day) == 2) { //輸入第一天幾人 以及查找第幾天
        sum = 0;
        while (sum < day) {  //當累積天數<想查找人數 則執行
            sum += n;
            n++;

        }
        printf("%d\n", n - 1); //當sum>=day 後 n++還會再執行一次 需要n-1
    }
}