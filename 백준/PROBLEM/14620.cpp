#include <iostream>
#include <algorithm>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, ret = 987654321, ground[11][11], visited[11][11];

int hap(int x, int y) {
  visited[x][y] = 1;
  int sum = ground[x][y];
  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    visited[nx][ny] = 1;
    sum += ground[nx][ny];
  }
  return sum;
}
bool check(int x, int y) {
  for(int i = 0; i < 4; i++) {
    if(visited[x][y])
      return 0;
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
      return 0;
  }
  return 1;
}

void eraseFlower(int x, int y) {
  visited[x][y] = 0;
  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    visited[nx][ny] = 0;
  }
}

void bfs(int cost, int cnt) {
  if(cnt == 3) {
    ret = min(ret, cost);
    return;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(check(i, j)) {
        bfs(cost + hap(i, j), cnt + 1);
        eraseFlower(i, j);
      }
    }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> ground[i][j];
    }
  }
  bfs(0, 0);
  cout << ret;
  return 0;
}