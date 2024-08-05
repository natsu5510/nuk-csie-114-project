#include <bits/stdc++.h>
using namespace std;
int N[2030];
//解題思路priority_queue 排序, 2 3 5 往上找?
//因為我不知道自己腦袋寫不寫得完所以打了這兩串註解ㄏ\

//但好像又不對 pq沒辦法連續輸出特定位數
//不過我連醜數怎麼生都還沒搞定 好煩@@
//priority_queue<long long, vector<long long>, greater<long long>> pq; //原來greater也要type嗎
int min3( int a, int b, int c ){
    if( a < b && a < c ){
        return a;
    }else if ( b < a && b < c ){
        return b;
    }else{
        return c;
    }
}

//最後不用pq 嘗試用比大小作
//做不出來
void ugly(){ //生成醜數
/*
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(5);
*/
    long long a = 2, b = 3, c = 5, num2 = 0, num3 = 0, num5 = 0;
    int i = 1;
    N[0] = 1;
    while( i <= 2030 ){
        N[i] = min3( a, b, c );
        if( N[i] == a ){
            num2++;
            a = N[num2]*2;
        }
        if( N[i] == b){
            num3++;
            b = N[num3]*3;
        }
        if( N[i] == c ){
            num5++;
            c = N[num5]*5;
        }
        i++;
    }
}


int main(){
    ugly();
    int in;

    while(cin >> in){
        cout << N[in-1] << '\n';
    }
}
//測試是錯的 加分88
