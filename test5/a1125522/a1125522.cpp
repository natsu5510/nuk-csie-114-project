/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int xmax,ymax;
    cin>>xmax>>ymax;
    int x,y,f;
    char d,face[4]={'N','E','S','W'};
    string s;
    while(cin>>x>>y>>d>>s)
    {
        bool l=0;
        for(int i=0;i<4;i++)
            if(d==face[i])
                f=i;
        for(auto i:s)
        {
            if(i=='R')
            {
                if(f==3)
                    f=0;
                else
                    f++;
            }
            if(i=='L')
            {
                if(f==0)
                    f=3;
                else
                    f--;
            }
            if(i=='F' && l!=1)
            {
                if(f==0)
                {
                    if(y+1>ymax)
                        l=1;
                    y++;
                }
                else if(f==1)
                {
                    if(x+1>xmax)
                        l=1;
                    x++;
                }
                else if(f==2)
                {
                    if(y-1<0)
                        l=1;
                    y--;
                }
                else if(f==3)
                {
                    if(x-1<0)
                        l=1;
                    x--;
                }
            }
           cout<<x<<" "<<y<<" "<<face[f]<<endl;
        }
        cout<<x<<" "<<y<<" "<<face[f];
        if(l==1)
            cout<<" "<<"LOST";   
        cout<<endl;
    }
    return 0;
}
