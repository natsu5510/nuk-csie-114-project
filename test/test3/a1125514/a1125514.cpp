#include<iostream>
using namespace std;
int main()
{
    long long s,d;
    while(cin>>s and !cin.eof())
    {
        cin>>d;
        while(s<d)
        {
            d -= s;
            s++;
        }
        cout<<s<<"\n";
    }
}
