#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int a, b, x, y, cnt = 0;
int m, n, k;
int rec[101][101];
int visited[101][101];
vector<int> ret;
int dfs(int y, int x) {
  visited[y][x] = 1;
  int ans = 1;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx] == 1) continue;
    if(rec[ny][nx] == 1) continue;
    ans += dfs(ny, nx);
  }
  return ans;
}

int main() {
  cin >> m >> n >> k;
  for(int i = 0; i < k; i++) {
    cin >> a >> b >> x >> y;
    for(int j = a; j < x; j++) {
      for(int k = b; k < y; k++) {
        rec[k][j] = 1;
      }
    }
  }
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      if(rec[i][j] != 1 && !visited[i][j]) {
        ret.push_back(dfs(i, j));
        cnt++;
      }
    }
  }
  sort(ret.begin(), ret.end());
  cout << cnt << '\n';
  for(int i = 0; i < ret.size(); i++) {
    cout << ret[i] << " ";
  }
  return 0;
}