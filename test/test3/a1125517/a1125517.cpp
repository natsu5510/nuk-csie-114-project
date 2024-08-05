#include <bits/stdc++.h>
using namespace std;
int main(){
    int s,d,x=0;
    cin>>s>>d;
    while(x<d){
        x+=s;
        s++;
    }
    cout<<s-1;
}
