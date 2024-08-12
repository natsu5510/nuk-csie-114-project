#include <iostream>

using namespace std;
bool isAnswer(int x);
int main()
{
    int a;
    int time=3,sum=3;
    int temp;
    while(cin>>a){
        if(a==1) cout << 1<<endl;
        if(a==2) cout << 2<<endl;
        if(a==3) cout<<3<<endl;
        while(1){
            sum++;
            if(isAnswer(sum)){
                time++;
            }
            if(time == a){
                cout << sum << endl;
                time = 3;
                sum  = 3;
                temp = 0;
                break;
            }
        }
    }
    return 0;
}
bool isAnswer(int x){
    bool test=false;
    while(1){
        if(x%2==0){
            x=x/2;
            test=true;
        }
        if(x%3==0){
            x=x/3;
            test=true;
        }
        if(x%5==0){
            x=x/5;
            test=true;
        }
        if(!test){
            return false;
            break;
        }
        if(test){
            test=false;
        }
        if(x==1){
            return true;
            break;
        }
    }
}
