#include <iostream>
#include <string>
#include <map>
using namespace std;

int start(char c){
  int current;
  if(c=='N')current=1;
  if(c=='E')current=2;
  if(c=='S')current=3;
  if(c=='W')current=4;
  return current;
}
int turn(int current,char c){
  if(c=='R')current++;
  if(c=='L')current--;
  if(current>4)current-=4;
  if(current<1)current+=4;
  return current;
}
int goy(int y,int current){
  if(current==1)y++;
  else y--;
  return y;
}
int gox(int x,int current){
  if(current==2)x++;
  else x--;
  return x;
}
char f(int current){
  char c;
  if(current==1)c='N';
  if(current==2)c='E';
  if(current==3)c='S';
  if(current==4)c='W';
  return c;
}
int main() {
  int borderx,bordery,x,y;
  char face;
  cin>>borderx>>bordery;
  while(cin>>x>>y>>face){
    int current=start(face);
    string order;
    bool flag=true;
    cin>>order;
    for(int i=0;i<order.length();i++){
      if(order[i]=='R'||order[i]=='L')current=turn(current,order[i]);
      else if(order[i]=='F'){
        if(current==1||current==3)y=goy(y,current);
        if(current==2||current==4)x=gox(x,current);
      }
      //cout<<current<<x<<y<<endl;
      if(x>borderx||y>bordery||x<0||y<0){
        if(x<0)x++;
        else if(x>borderx)x--;
        else if(y<0)y++;
        else if(y>bordery)y--;
        cout<<x<<" "<<y<<" "<<f(current)<<" "<<"LOST"<<endl;
        flag=false;
        break;
      }
    }
    if(flag)cout<<x<<" "<<y<<" "<<f(current)<<endl;
  }
}