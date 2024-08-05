#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct POINT {
    int x;
    int y;
};

int main(void) {
    vector<int> vecScent;
    
    char szIns[100], szOri[4] = {'N', 'E', 'S', 'W'};
    
    POINT ptSize, ptPos, ptOri[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    cin >> ptSize.x >> ptSize.y;
    
    for (char cOri; cin >> ptPos.x >> ptPos.y >> cOri >> szIns; ) {
        int nOri = find(&szOri[0], &szOri[4], cOri) - &szOri[0], i = 0;
        
        for (; szIns[i] != 0; ++i) {
            if (szIns[i] != 'F') {
                nOri = (nOri + (szIns[i] == 'L' ? 3 : 1)) % 4;
                continue;
            }
            
            POINT ptNew = {ptPos.x + ptOri[nOri].x, ptPos.y + ptOri[nOri].y};
            
            if (ptNew.x >= 0 && ptNew.x <= ptSize.x && ptNew.y >= 0 && ptNew.y <= ptSize.y) {
                ptPos = ptNew;
                continue;
            }
            
            int nScent = ptPos.y * 51 + ptPos.x;
            
            vector<int>::iterator iEnd = vecScent.end();
            
            if (find(vecScent.begin(), iEnd, nScent) == iEnd) {
                vecScent.push_back(nScent);
                break;
            }
        }
        
        cout << ptPos.x << ' ' << ptPos.y << ' ' << szOri[nOri];
        cout << ((szIns[i] == 0) ? "" : " LOST") << endl;
    }
    
    return 0;
}