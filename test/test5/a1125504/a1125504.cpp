#include <bits/stdc++.h>
using namespace std;

int main(){
    int land_x, land_y, x, y, check, flag;
    char face;
    string move;
    int scent[100][100];

    cin >> land_x >> land_y;

    while(cin >> x >> y >> face){
        check = 0;
        flag = 0;
        cin >> move;
        
        for(int i = 0; i < move.length(); i++){
            if(move[i] == 'L'){
                if(face == 'N') face = 'W';
                else if(face == 'W') face = 'S';
                else if(face == 'S') face = 'E';
                else if(face == 'E') face = 'N';
            }
            else if(move[i] == 'R'){
                if(face == 'N') face = 'E';
                else if(face == 'W') face = 'N';
                else if(face == 'S') face = 'W';
                else if(face == 'E') face = 'S';
            }
            else if(move[i] == 'F'){
                if(scent[x][y]==1) check = 1;
                if(face == 'N') y++;
                else if(face == 'E') x++;
                else if(face == 'S') y--;
                else if(face == 'W') x--;
            }

            if(check == 1){
                if(x > land_x) x -= 1;
                else if(y > land_y) y -= 1;
                else if(x < 0) x += 1;
                else if(y < 0) y += 1;
            }

            if(x > land_x || y > land_y || x < 0 || y < 0){
                flag = 1;
                if(x > land_x) x -= 1;
                else if(y > land_y) y -= 1;
                else if(x < 0) x += 1;
                else if(y < 0) y += 1;

                scent[x][y] = 1;
                break;
            }
        }
        if(flag == 1) cout << x << " " << y << " " << face << " " << "LOST" << endl;
        else cout << x << " " << y << " " << face << endl;
    }
}