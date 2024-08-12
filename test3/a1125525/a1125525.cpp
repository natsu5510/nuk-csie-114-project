#include <iostream>

using namespace std;

int main(){
    int s,d;
    while(cin >> s >> d){
    int x=0;
    while(x<d)
    {
        x=x+s;
        s++;
    }
    s--;
    cout << s << endl;
   
    }
    

   return 0;
}