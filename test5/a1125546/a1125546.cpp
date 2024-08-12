#include<iostream>
#include<string>

using namespace std;

int main() {
	int b1 = 0, b2 = 0;
	int x = 0, y = 0;
	char way;
	string todo;

	cin >> b1 >> b2;
	while (cin >> x >> y >> way) {
		cin >> todo;
		for (int i = 0; i < todo.length(); i++) {
			if (todo[i] == 'F') {
				if (way == 'E') x += 1;
				else if (way == 'S') y -= 1;
				else if (way == 'W') x -= 1;
				else if (way == 'N') y += 1;
			}
			else if (todo[i] == 'R') {
				if (way == 'E') way = 'S';
				else if (way == 'S') way = 'W';
				else if (way == 'W') way = 'N';
				else if (way == 'N') way = 'E';
			}
			else if (todo[i] == 'L') {
				if (way == 'E') way = 'N';
				else if (way == 'S') way = 'E';
				else if (way == 'W') way = 'S';
				else if (way == 'N') way = 'W';
			}
			if (x < 0 || x > b1 || y < 0 || y > b2) break;
		}
		if (x < 0) cout << 0 << " " << y << " W " << "LOST" << endl;
		else if (x > b1) cout << b1 << " " << y << " E " << "LOST" << endl;
		else if (y < 0) cout << x << " " << 0 << " S " << "LOST" << endl;
		else if (y > b2) cout << x << " " << b2 << " N " << "LOST" << endl;
		else cout << x << " " << y << " " << way << endl;
	}
}