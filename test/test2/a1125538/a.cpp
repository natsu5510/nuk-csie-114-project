#include<stdio.h>

int main(){
long a=0;
int number;

scanf("%d",&number);

while(1){
        a++;
        while(a%2==0){
            a=a/2;
        }
        while(a%5==0){
            a=a/5;
        }
        while(a%3==0){
            a=a/3;
        }

        if(a==1){


            number--;
        }

    if(number==0){
        break;
    }



}

printf("%d" , a);

}
