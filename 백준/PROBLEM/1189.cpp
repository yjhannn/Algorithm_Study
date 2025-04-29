#include <iostream>

using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int R, C, K, visited[6][6];
char a[6][6];

int bfs(int x, int y) {
  if(x == 0 && y == C-1) {
    if(K == visited[x][y])
      return 1;
    return 0;
  }
  int ans = 0;
  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny] || a[nx][ny] == 'T')
      continue;
    visited[nx][ny] = visited[x][y] + 1;
    ans += bfs(nx, ny);
    visited[nx][ny] = 0;
  }
  return ans;
}

int main() {
  cin >> R >> C >> K;
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      cin >> a[i][j];
    }
  }
  visited[R-1][0] = 1;
  cout << bfs(R-1, 0);
  return 0;
}