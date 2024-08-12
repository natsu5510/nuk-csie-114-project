#include <bits/stdc++.h>

using namespace std;

int temp, k = -1;
pair<int, int>map_size, robot_location;
char face;
char direction[4] = {'N', 'E', 'S', 'W'};
string moves;
map <char, int>direction_map;
vector< pair<int, int> >ans , warndir;
bool isFall = false;

bool warn(int x, int y){
    for(int i = 0; i < warndir.size(); i++){
        if(warndir[i].first == x && warndir[i].second == y){
            if(face == 'N')robot_location.second -= 1;
            else if(face == 'E')robot_location.first -= 1;
            else if(face == 'S')robot_location.second += 1;
            else if(face == 'W')robot_location.first += 1;
            return true;
        }
    }
    return false;
}


int main(){
    direction_map['N'] = 0;
    direction_map['E'] = 1;
    direction_map['S'] = 2;
    direction_map['W'] = 3;
    cin >> map_size.first >> map_size.second;
    while(cin >> robot_location.first >> robot_location.second >> face){
        isFall = false;
        ans.clear();
        k = -1;
        temp = direction_map[face];
        cin >> moves;
        for(int i = 0;i < moves.length(); i++){
            if(moves[i] == 'R')temp = direction_map[face] + 1;
            else if(moves[i] == 'L')temp = direction_map[face] - 1;
            else if(moves[i] == 'F'){
                if(face == 'N')robot_location.second += 1;
                else if(face == 'E')robot_location.first += 1;
                else if(face == 'S')robot_location.second -= 1;
                else if(face == 'W')robot_location.first -= 1;
            }
            if(temp > 3)temp = 0;
            else if(temp < 0)temp = 3;
            face = direction[temp];
            if(robot_location.first < 0 || robot_location.first > map_size.first || robot_location.second < 0 || robot_location.second > map_size.second){
                if(warn(robot_location.first, robot_location.second))continue;
                else warndir.push_back(make_pair(robot_location.first, robot_location.second));
                isFall = true;
                break;
            }
            ans.push_back(make_pair(robot_location.first, robot_location.second)); 
        }
        cin.ignore();
        cout << ans[ans.size()-1].first << " " << ans[ans.size() - 1].second << " " << face;
        if(isFall)cout << " LOST";
        cout << "\n";
    }
}