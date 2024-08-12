#include <bits/stdc++.h>

using namespace std;

int main()
{
   int s,d,ans;
    while(cin>>s>>d)
    {
        int day=1;
        while(day<=d)
        {
            day+=s;
            s++;
        }
        s--;
        cout<<s<<endl;
    }


    return 0;
}
