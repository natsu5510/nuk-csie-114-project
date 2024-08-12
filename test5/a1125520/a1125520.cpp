#include <bits/stdc++.h>
using namespace std;
string trun( string D , string LR );
bool scent[52][52] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int MaxX, MaxY;
    cin >> MaxX >> MaxY;
    
    int CurX, CurY;
    string Dir;
    string DirToInt = "NESW";
    bool flag;
    int IntDir;
    while( cin >> CurX >> CurY >> Dir ){
        flag = false;
        string Command;
        cin >> Command;
        for( int i = 0 ; i < 4 ; i++ ){
            if( DirToInt[i] == Dir[0] ) IntDir = i; 
        }
        for( int i = 0 ; i < Command.size() ; i++ ){
            if( Command[i] == 'F' ){
                switch(IntDir){
                    case 0:
                        CurY++;
                        break;
                    case 3:
                        CurX--;
                        break;
                    case 1:
                        CurX++;
                        break;
                    case 2:
                        CurY--;
                        break;
                    default:
                        ;
                }
                if( CurX > MaxX ){
                    CurX--;
                    if( !scent[CurX][CurY] ){
                        cout << CurX << " " << CurY << " " << DirToInt[IntDir] << " LOST\n";
                        scent[CurX][CurY] = true;
                        flag = true;
                    }
                }else if( CurX < 0 ){
                    CurX++;
                    if( !scent[CurX][CurY] ){
                        cout << CurX << " " << CurY << " " << DirToInt[IntDir] << " LOST\n";
                        scent[CurX][CurY] = true;
                        flag = true;
                    }
                }else if( CurY > MaxY ){
                    CurY--;
                    if( !scent[CurX][CurY] ){
                        cout << CurX << " " << CurY << " " << DirToInt[IntDir] << " LOST\n";
                        scent[CurX][CurY] = true;
                        flag = true;
                    }
                }else if( CurY < 0 ){
                    CurY++;
                    if( !scent[CurX][CurY] ){
                        cout << CurX << " " << CurY << " " << DirToInt[IntDir] << " LOST\n";
                        scent[CurX][CurY] = true;
                        flag = true;
                    }
                }
            }else{
                if( Command[i] == 'R' ){
                    IntDir = ( IntDir + 1 ) % 4;
                }else{
                    IntDir--;
                    if( IntDir < 0 ) IntDir = 3;
                }
            }
        }
        if(!flag){
            cout << CurX << " " << CurY << " " << DirToInt[IntDir] << '\n';
        }
    }
}