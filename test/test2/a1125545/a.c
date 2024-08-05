#include"stdio.h"

int main(){
    int N , i=1 , m=1 ;
    char arr[100000];
    scanf("%d",&N);
    while(i<=N){
        if(m%2==0||m%3==0||m%5==0||m==1){
            arr[i]=m;
            i=i+1;
        }
        m=m+1 ;

        
    }
    printf("%d",arr[N]);
    return 0;

}