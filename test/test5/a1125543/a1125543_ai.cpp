#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, x, y;
    char z;
    string s;
    cin >> a >> b;
    int mp[a + 1][b + 1] = { 0 };
    while (cin >> x >> y >> z >> s) {
        bool ok = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') {
                if (z == 'E') {
                    z = 'S';
                }
                else if (z == 'S') {
                    z = 'W';
                }
                else if (z == 'W') {
                    z = 'N';
                }
                else if (z == 'N') {
                    z = 'E';
                }
            }
            else if (s[i] == 'L') {
                if (z == 'E') {
                    z = 'N';
                }
                else if (z == 'S') {
                    z = 'E';
                }
                else if (z == 'W') {
                    z = 'S';
                }
                else if (z == 'N') {
                    z = 'W';
                }
            }
            else if (s[i] == 'F') {
                if (z == 'E') {
                    x++;
                }
                else if (z == 'S') {
                    y--;
                }
                else if (z == 'W') {
                    x--;
                }
                else if (z == 'N') {
                    y++;
                }
            }
            if (x<0 || y<0 || x>a || y>b) {
                if (z == 'E') {
                    x--;
                }
                else if (z == 'S') {
                    y++;
                }
                else if (z == 'W') {
                    x++;
                }
                else if (z == 'N') {
                    y--;
                }
                if (mp[x][y] == 1) {
                    continue;
                }
                mp[x][y] = 1;
                ok = false;
                break;

            }
        }
        if (ok) {
            cout << x << " " << y << " " << z << endl;
        }
        else {
            cout << x << " " << y << " " << z << " " << "LOST" << endl;
        }
    }
}
