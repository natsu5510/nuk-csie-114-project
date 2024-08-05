#include <stdio.h>
#include <math.h>


// 定義一個函數，傳入兩個參數，S是第一組旅行團的人數，D是要查詢的天數
// 回傳值是在第D天入住的旅行團的人數
int hotel(int S, int D) {
  // 宣告一個變數ans，用來儲存答案
  int ans;
  // 使用數學公式來計算答案，公式如下：
  // ans = (sqrt(8 * D + (2 * S - 1) * (2 * S - 1)) + 2 * S - 1) / 2
  // 公式的推導過程可以參考網站
  ans = (sqrt(8 * D + (2 * S - 1) * (2 * S - 1)) + 2 * S - 1) / 2;
  // 回傳ans
  return ans;
}


int main() {
  // 宣告兩個變數，用來儲存輸入的S和D
  int S, D;
  // 用一個迴圈，讀取每一行的輸入，直到沒有輸入為止
  while (scanf("%d %d", &S, &D) != EOF) {
    // 呼叫hotel函數，傳入S和D，並將回傳值印出
    printf("%d\n", hotel(S, D));
  }
  // 程式結束，回傳0
  return 0;
}