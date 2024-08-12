
#include <bits/stdc++.h>

using namespace std;

std::vector<pair<int,int>> v;
int fnd(int a,int b)
{
    bool f=0;
    for(auto i:v)
    {   
        if(i.first==a && i.second==b)
        {
            f=1;
            return 1;
        }
    }
    if(f==0)
        return 0;
}
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
                    if(y+1>ymax&&fnd(x,y)==0)
                        l=1;
                    else if(fnd(x,y)==0)
                        y++;
                }
                else if(f==1)
                {
                    if(x+1>xmax&&fnd(x,y)==0)
                        l=1;
                    else if(fnd(x,y)==0)
                        x++;
                }
                else if(f==2)
                {
                    if(y-1<0&&fnd(x,y)==0)
                        l=1;
                    else if(fnd(x,y)==0)
                        y--;
                }
                else if(f==3)
                {
                    if(x-1<0&&fnd(x,y)==0)
                        l=1;
                    else if(fnd(x,y)==0)
                        x--;
                }
                   
            }
        }
        cout<<x<<" "<<y<<" "<<face[f];
        if(l==1)
        {
            pair<int,int> tmp;
            tmp.first=x;
            tmp.second=y;
            cout<<" "<<"LOST";
            v.push_back(tmp);
        }
               
        cout<<endl;
    }
    return 0;
}
