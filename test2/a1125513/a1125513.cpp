#include <iostream>
using namespace std;
int main()
{
    long long int n,g,m,z;
    while(cin>>n)
    {
        n-=1;
        for (g = 2 ; g<=2023;g++)
        {
            if(g%2 == 0 || g%3==0 || g%5==0)
            {
                while(g%2!=1)
                {
                    g = g/2;
                }
                while(g%3!=2 && g%3!=1)
                {
                    g = g/3;
                }
                while(g%5!=1 && g%5!=2 && g%5!=3 && g%5!=4 )
                {
                    g = g/5;
                }
                if(g==1)
                {
                    z+=1;
                }

            }
            if(z==n)
            {
                cout<<g;
            }
        }

    }
}
