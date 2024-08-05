
#include <iostream>
int main()
{
   int N;
   int i;
   int R=1; //紀錄順序
   while(1){
   scanf("%d",&N);
   if(N==1){
     printf("%d",N);
     break; 
   }
   while(1){
       i=2;
       if(i%2==0||i%3==0||i%5==0){
        R+=1;
       }
       i+=1;
       if(R==N){
           break;
       }
  }
    
      
      
   
  printf("%d\n",i);
}
}
