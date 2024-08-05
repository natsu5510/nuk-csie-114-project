#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// 方向枚举
enum Direction { N, E, S, W };

// 位置结构体
struct Position {
  int x, y;
  Direction dir;
};

// 将方向字符转换为枚举类型
Direction charToDirection(char c) {
  switch (c) {
    case 'N':
      return N;
    case 'E':
      return E;
    case 'S':
      return S;
    case 'W':
      return W;
  }
  return N;  // 默认返回北
}

// 将方向枚举转换为字符类型
char directionToChar(Direction dir) {
  switch (dir) {
    case N:
      return 'N';
    case E:
      return 'E';
    case S:
      return 'S';
    case W:
      return 'W';
  }
  return 'N';  // 默认返回北
}

// 方向转向处理
Direction turnLeft(Direction dir) {
  return static_cast<Direction>((dir + 3) % 4);
}

Direction turnRight(Direction dir) {
  return static_cast<Direction>((dir + 1) % 4);
}

// 定义移动方向的偏移量
int dx[] = {0, 1, 0, -1};  // N, E, S, W
int dy[] = {1, 0, -1, 0};

int main() {
  int maxX, maxY;
  cin >> maxX >> maxY;

  set<pair<int, int>> scent;  // 存储失踪机器人的气味

  int x, y;
  char dirChar;
  string instructions;

  while (cin >> x >> y >> dirChar) {
    cin >> instructions;

    Position pos = {x, y, charToDirection(dirChar)};
    bool lost = false;

    for (char instr : instructions) {
      if (instr == 'L') {
        pos.dir = turnLeft(pos.dir);
      } else if (instr == 'R') {
        pos.dir = turnRight(pos.dir);
      } else if (instr == 'F') {
        int newX = pos.x + dx[pos.dir];
        int newY = pos.y + dy[pos.dir];

        if (newX < 0 || newX > maxX || newY < 0 || newY > maxY) {
          if (scent.count({pos.x, pos.y}) == 0) {
            lost = true;
            scent.insert({pos.x, pos.y});
            break;
          }
        } else {
          pos.x = newX;
          pos.y = newY;
        }
      }
    }

    cout << pos.x << " " << pos.y << " " << directionToChar(pos.dir);
    if (lost) {
      cout << " LOST";
    }
    cout << endl;
  }

  return 0;
}
