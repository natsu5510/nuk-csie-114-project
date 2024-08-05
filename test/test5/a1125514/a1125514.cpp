#include<iostream>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    int lx,ly;
    cin>>lx>>ly;
    int x,y;
    string b;
    int lost[55][55]={0};
    while(cin>>x>>y>>b)
    {
        string base="NESW";
        int r;
        for(int i=0;i<base.length();i++)
        {
            if(base[i]==b[0])
            {
                r=i;
                break;
            }
        }
        string s;
        bool flag=false;
        cin.ignore();
        getline(cin,s);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='R')
            {
                r=(r+1)%4;
            }
            else if(s[i]=='L')
            {
                r=(r+3)%4;
            }
            else if(s[i]=='F')
            {
                int nx=x+dx[r];
                int ny=y+dy[r];
                if(nx<0 or nx>lx or ny<0 or ny>ly)
                {
                    if(lost[x][y]==1)
                    {
                        continue;
                    }
                    else
                    {
                        lost[x][y]=1;
                        flag=true;
                        cout<<x<<" "<<y<<" "<<base[r]<<" LOST"<<endl;
                        break;
                    }
                }
                else
                {
                    x=nx;
                    y=ny;
                }
            }
        }
        if(!flag)
        {
            cout<<x<<" "<<y<<" "<<base[r]<<endl;
        }
    }
}