#include <iostream>
using namespace std;

int main() {
  int s,d,count=0;
  cin >> s >> d;
  while(count < d){
    count += s;
    s++;
  }
  cout << s-1;
}