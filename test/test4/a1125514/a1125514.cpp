#include<iostream>
using namespace std;
int main()
{
    int n;
    long long a,temp;
    while(cin>>n and !cin.eof())
    {
        a=1;
        for(int i=1;i<=n;)
        {
            temp = a;
            while (temp!=1)
            {
                if(temp%2==0)
                {
                    temp/=2;
                    continue;
                }
                else if(temp%3==0)
                {
                    temp/=3;
                    continue;
                }
                else if(temp%5==0)
                {
                    temp/=5;
                    continue;
                }
                else
                {
                    break;
                }
            }
            if(temp==1)
            {
                i++;
            }
            a++;
        }
        a--;
        cout<<a<<endl;
    }
}
