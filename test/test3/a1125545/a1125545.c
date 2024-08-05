#include "stdio.h"
#include "string.h"



int main() {
    int n,day;
    scanf("%d",&n);
    scanf("%d",&day);
    while(day>n){
        day -= n;
        n++ ;
    }
    printf("%d",n);
    return 0;

   
}