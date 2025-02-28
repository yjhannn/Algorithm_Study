// DFS 응용
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, ans, ans2;
int a[101][101], visited[101][101];
vector<pair<int, int> > cz;
void go(int y, int x) {
  visited[y][x] = 1;
  if(a[y][x] == 1) {
    cz.push_back(make_pair(y, x));
    return;
  }
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
      continue;
    go(ny, nx);
    }
  return;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  while(1) {
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
    cz.clear();
    go(0,0);
    ans2 = cz.size();
    // 치즈 녹이는 로직(1->0)
    for(pair<int, int> b : cz) {
      a[b.first][b.second] = 0;
    }
    bool check = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(a[i][j] != 0)
          check = 1;
      }
    }
    ans++;
    if(check == 0)
      break;
  }
  cout << ans << '\n' << ans2;
  
}