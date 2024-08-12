#include <bits/stdc++.h>

using namespace std; 
unsigned long int n , times = 1 , ans = 1 , i = 2 , j = 0;
bool t = true;

int main(){
    cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    while(times < n){
        j = i;
        while(j > 1){
            if(j % 2 == 0)j /= 2;
            else if(j % 3 == 0)j /= 3;
            else if(j % 5 == 0)j /= 5;
            else {
                t = false;
                break;
            }
        }
        if(t == true){
            ans = i;
            times ++;

        }else t = true;
        i ++;
    }
    cout << ans;
}