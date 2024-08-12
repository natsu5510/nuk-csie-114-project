#include <stdio.h>
#include <math.h>

int main()
{
    int N=0;
    int i=0;
    int ugly[i];
    int a=0;
    int b=0;

    while(scanf("%d",&N)){     //輸入N告訴我第N個ugly number
            if(N>2023){
                return 0;     //若N>2023則結束程式碼
            }
            if(N<1){
                return 0;      //若N<1則結束程式碼
            }
             //先定義ugly number
            while(a<=2023){
                    if(a%2==0&&a%7!=0||a%3==0&&a%7!=0||a%5==0&&a%7!=0){
                        b = a; //把a放到b
                        ugly[i]=b; //把b放入陣列,ugly[i]=b;代表第i個ugly number為b
                        i++;   //讓上面的ugly[i]在下一輪迴圈中變成ugly[i+1]
                    }
            a++;  //讓a加到>2023為止
            }
            i = N;   //讓N=i
            ugly[i]=b;
            printf("%d",b);
        
        }


    return 0;
}
























