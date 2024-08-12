#include <stdio.h>
 
int main(void) {
  int num, date, nums, total = 0;
  scanf("%d %d", &num, &date);
  while(num < date){
    nums = num + 1;
    total = (num * 2 + nums - 1) * nums / 2;
    if(total >= date){
      printf("%d", nums);
    }
    else{
      break;
    }
  }
}
