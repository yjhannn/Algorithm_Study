#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int n, m, h, ans = INF;
int visited[300][11], a[300][11];

bool check() {
  for(int i = 1; i <= n; i++) {
    int start = i;
    for(int j = 1; j <= h; j++) {
      if(visited[j][start])
        start++;
      else if(visited[j][start-1])
        start--;
    }
    if(i != start)
      return false;
  }
  return true;
}

void solve(int here, int cnt) {
  if(cnt > 3 || cnt >= ans)
    return;
  if(check()) {
    ans = min(ans, cnt);
    return;
  }  
  for(int i = here; i <= h; i++) {
    for(int j = 1; j < n; j++) {
      if(visited[i][j] || visited[i][j-1] || visited[i][j+1])
        continue;
      visited[i][j] = 1;
      solve(i, cnt + 1);
      visited[i][j] = 0;
    }
  }
}

int main() {
  cin >> n >> m >> h;
  if(m == 0) {
    cout << 0;
    return 0;
  }
  int a, b;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    visited[a][b] = 1;
  }
  solve(1, 0);
  if(ans == INF)
    cout << -1;
  else
    cout << ans;

  return 0;
}