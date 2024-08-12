#include <iostream>
#include<string>

using namespace std;

int grid[51][51] = {0};
int main()
{
    int grid_x, grid_y;
    cin>>grid_x>>grid_y;
    char c;
    int init_x, init_y;
    while(cin>>init_x>>init_y>>c)
    {
        int final_x, final_y;
        char final_c;
        bool isLost = 0;
        string str;
        cin>>str;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == 'R')
            {
                if(c == 'N')
                    c = 'E';
                else if(c == 'E')
                    c = 'S';
                else if(c == 'S')
                    c = 'W';
                else if(c == 'W')
                    c = 'N';
            }
            else if(str[i] == 'L')
            {
                if(c == 'N')
                    c = 'W';
                else if(c == 'E')
                    c = 'N';
                else if(c == 'S')
                    c = 'E';
                else if(c == 'W')
                    c = 'S';
            }
            else if(str[i] == 'F')
            {
                if(c == 'N')
                {
                    init_y++;
                    if(init_y > grid_y && grid[init_x][init_y - 1])
                        init_y--;
                }
                else if(c == 'E')
                {
                    init_x++;
                    if(init_x > grid_x && grid[init_x - 1][init_y])
                        init_x--;
                }
                else if(c == 'S')
                {
                    init_y--;
                    if(init_y < 0 && grid[init_x][init_y + 1])
                        init_y++;
                }
                else if(c == 'W')
                {
                    init_x--;
                    if(init_x < 0 && grid[init_x + 1][init_y])
                        init_x++;
                }
                if(init_x < 0)
                {
                    final_x = 0;
                    final_y = init_y;
                    final_c = c;
                    isLost = 1;
                    break;
                }
                else if(init_y < 0)
                {
                    final_x = init_x;
                    final_y = 0;
                    final_c = c;
                    isLost = 1;
                    break;
                }
                else if(init_x > grid_x)
                {
                    final_x = grid_x;
                    final_y = init_y;
                    final_c = c;
                    isLost = 1;
                    break;
                }
                else if(init_y > grid_y)
                {
                    final_x = init_x;
                    final_y = grid_y;
                    final_c = c;
                    isLost = 1;
                    break;
                }
            }
        }
        if(!isLost)
        {
            final_x = init_x;
            final_y = init_y;
            final_c = c;
            cout<<final_x<<" "<<final_y<<" "<<final_c<<endl;
        }
        else
        {
            grid[final_x][final_y] = 1;
            cout<<final_x<<" "<<final_y<<" "<<final_c<<" LOST"<<endl;
        }
        
    }

    return 0;
}

