#include <iostream>
using namespace std;

int depend(int num){
   while (num%2==0||num%3==0|num%5==0)
   {
     if(num%2==0)
        num/=2;
    if(num%5==0)
        num/=5;
    if(num%3==0)
        num/=3;
    if(num==1)
        return 1;
   }
   return 0;
   
}

int main(){

    int input;
    
    while (cin >> input)
    {
        int ulgy[2023];
        int a=2,i=1;
        ulgy[i]=1;//pos 1 = 1
        while (input!=i)
        {
            if(depend(a)){
                i++;// start from 2
                ulgy[i]=a;
            }
            a++;
        }
        //cout << i << endl;
        cout << ulgy[i] << endl;
    }
    
   return 0;
}