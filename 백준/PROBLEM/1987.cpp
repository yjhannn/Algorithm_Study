#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
string input;
char a[21][21];
int r, c, ans, visited[27];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y, int ret) {
  ans = max(ans, ret);
  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 0 || nx >= r || ny < 0 || ny >= c || visited[a[nx][ny] - 65])
      continue;
    visited[a[nx][ny] - 65] = 1;
    dfs(nx, ny, ret + 1);
    visited[a[nx][ny] - 65] = 0;
  }
}

int main() {
  cin >> r >> c;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> a[i][j];
    }
  }
  visited[a[0][0] - 65] = 1;
  dfs(0, 0, 1);
  cout << ans;
}
