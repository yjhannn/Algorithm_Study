// 구현방법
// 1. 상어 위치 저장
// 2. 낚시 및 상어 이동 메서드(상어 겹치면 크기 작은 상어 삭제)
// 3. 시간 증가 및 낚시꾼 이동 및 메서드 호출
#include <iostream>
using namespace std;
struct Shark {
  int x, y, s, d, z;
}info[10001];
int dx[] = {0, -1, 1, 0, 0}; // 1: 위, 2: 아래, 3: 오른쪽, 4: 왼쪽
int dy[] = {0, 0, 0, 1, -1};
int r, c, m, pos, ret, a[101][101];

void fishing(int here) {
  for(int i = 1; i <= r; i++) {
    if(a[i][here] != 0) {
      ret += a[i][here];
      for(int j = 0; j < m; j++) {
        if(info[j].z == a[i][here] && info[j].x == i && info[j].y == here) {
          info[j].z = 0; // 잡힌 상어 제거
          break;
        }
      }
      a[i][here] = 0;
      return;
    }
  }
}

void move() {
  int temp[101][101] = {0};
  for(int i = 0; i < m; i++) {
    if(info[i].z == 0) continue;

    int x = info[i].x;
    int y = info[i].y;
    int s = info[i].s;
    int d = info[i].d;
    int z = info[i].z;

    if(d == 1 || d == 2) s %= (2 * (r - 1));
    else s %= (2 * (c - 1));

    for(int j = 0; j < s; j++) {
      if(d == 1 && x == 1) d = 2;
      else if(d == 2 && x == r) d = 1;
      else if(d == 3 && y == c) d = 4;
      else if(d == 4 && y == 1) d = 3;

      x += dx[d];
      y += dy[d];
    }

    info[i].x = x;
    info[i].y = y;
    info[i].d = d;

    if(temp[x][y] == 0 || info[temp[x][y] - 1].z < z) {
      if(temp[x][y] != 0) info[temp[x][y] - 1].z = 0;
      temp[x][y] = i + 1;
    } else {
      info[i].z = 0;
    }
  }

  for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++)
      a[i][j] = 0;

  for(int i = 0; i < m; i++)
    if(info[i].z != 0)
      a[info[i].x][info[i].y] = info[i].z;
}

int main() {
  cin >> r >> c >> m;
  for(int i = 0; i < m; i++) {
    cin >> info[i].x >> info[i].y >> info[i].s
    >> info[i].d >> info[i].z;
    a[info[i].x][info[i].y] = info[i].z;
  }
  int man_cur = 1;
  while(1) {
    if(man_cur == c + 1)
      break;
    fishing(man_cur);
    move();
    man_cur++;
  }
  cout << ret;
  return 0;
}