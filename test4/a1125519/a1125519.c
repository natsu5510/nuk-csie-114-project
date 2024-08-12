#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Divide(int a, int b)
{   while (a % b == 0){
    a = a / b;
    }
    return a;
}
int Uglynumber(int a){
    int array[2023]={0};
    int i=1;
    array[i]=1;
    i++;
    int temp = 0;
    for(int b=2;b<=2023;b++){
        temp = b;
        temp = Divide(temp, 2);
        temp = Divide(temp, 3);
        temp = Divide(temp, 5);
        if(temp==1){
            array[i] = b;
            i++;
        }
    }
    return array[a];
}
int main()
{
    int n=0;
    scanf("%d",&n);
    printf("%d",Uglynumber(n));
}

