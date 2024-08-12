#include<iostream>
using namespace std;

int main(){
    int a=0,b=0,ans=1;
    cin >> a >> b;
    int x=0,y=0;
    int p[a+2][b+2]={0};
    char d;
    string s;
    while(cin >> x >> y >> d >> s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='R'){
            if(d=='E'){
                d='S';
            }
            else if(d=='S'){
                d='W';
            }
             else if(d=='W'){
                d='N';
            }
             else if(d=='N'){
                d='E';
            }
        }
        if(s[i]=='L'){
            if(d=='E'){
                d='N';
            }
             else if(d=='S'){
                d='E';
            }
             else if(d=='W'){
                d='S';
            }
             else if(d=='N'){
                d='W';
            }
        }
        if(s[i]=='F'){
            if(d=='E'){
                x++;
            }
            else if(d=='S'){
                y--;
            }
             else if(d=='W'){
                x--;
            }
             else if(d=='N'){
                y++;
            }
        }
        if(x>a||y>>b){
            if(d=='E'){
                x--;
            }
             else if(d=='S'){
                y++;
            }
             else if(d=='W'){
                x++;
            }
             else if(d=='N'){
                y--;
            }
        ans=0;
        break;
        }
    }
    if(ans==0)cout<< x <<" "<< y <<" "<< d <<" LOST\n";
    else cout<< x <<" "<< y <<" "<< d <<endl;
}
return 0;
}
