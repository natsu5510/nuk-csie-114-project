#include <stdio.h>

int main(void) {
  int first,day,ans=0;
  
  while(scanf("%d %d",&first,&day)!=EOF){
  ans=first;
  while(day>0){
   day=day-first;
   first++;
  }
  if(day<=0)first--;
  printf("%d\n",first);
  }
}