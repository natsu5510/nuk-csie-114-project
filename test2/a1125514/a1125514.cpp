#include<iostream>
using namespace std;
int main()
{
    int n,count;
    long int temp,i;
    while(cin>>n and !cin.eof())
    {
        temp = 2;
        count = 1;
        while(count != n)
        {
            i = temp;
            while(i%2==0)
            {
                i/=2;
            }
            while(i%5==0)
            {
                i/=5;
            }
            while(i%3==0)
            {
                i/=3;
            }
            if(i==0)
            {
                count++;
            }
            if(count == n)
            {
                break;
            }
            temp++;
        }

        cout<<temp<<"\n";

    }
}