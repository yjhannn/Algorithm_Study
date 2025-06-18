#include <iostream>
#include <queue>
using namespace std;

int dx[] = {0, 1, 0, -1}; // 동, 남, 서, 북 (시계방향)
int dy[] = {1, 0, -1, 0};

int n, k, l;
int a[101][101]; // 0: 빈칸, 1: 뱀, 2: 사과
queue<pair<int, char>> dirInfo;

int rotate(int dir, char c) {
  if (c == 'L') return (dir + 3) % 4; // 반시계
  else return (dir + 1) % 4; // 시계
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    a[x][y] = 2; // 사과
  }
  cin >> l;
  for (int i = 0; i < l; i++) {
    int x;
    char c;
    cin >> x >> c;
    dirInfo.push({x, c});
  }

  deque<pair<int, int>> snake;
  snake.push_back({1, 1});
  a[1][1] = 1;
  int time = 0, dir = 0;

  while (true) {
    time++;
    int nx = snake.front().first + dx[dir];
    int ny = snake.front().second + dy[dir];

    // 충돌 체크
    if (nx < 1 || ny < 1 || nx > n || ny > n || a[nx][ny] == 1) break;

    // 이동
    if (a[nx][ny] == 2) {
      // 사과 있음: 머리만 이동
      a[nx][ny] = 1;
      snake.push_front({nx, ny});
    } else {
      // 사과 없음: 머리 이동 + 꼬리 제거
      a[nx][ny] = 1;
      snake.push_front({nx, ny});
      int tx = snake.back().first;
      int ty = snake.back().second;
      a[tx][ty] = 0;
      snake.pop_back();
    }

    if (!dirInfo.empty() && dirInfo.front().first == time) {
      dir = rotate(dir, dirInfo.front().second);
      dirInfo.pop();
    }
  }

  cout << time << '\n';
  return 0;
}