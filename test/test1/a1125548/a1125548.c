#include <stdio.h>

int main(void) {

  while(1>0){
  int s, d, sum = 0;
  scanf("%d %d",&s,&d);

  while(1>0){
    sum = sum + s;
    if(sum >= d && sum-d <= s) break;
    s++;
  }

  printf("%d",s);
  }
  return 0;
}
