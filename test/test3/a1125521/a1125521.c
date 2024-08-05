#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
  int s,d;
  scanf("%d%d", &s,&d);
  while(1){
    int n;
    d=d-s;
    if(d<=0){
      break;
    }
    else
      s++;
  }
  printf("%d",s);
  return 0;
}