#include <iostream>
#include <vector>
#include <queue>
using namespace std; 
const int INF = 987654321;
int n, m, mx, my, ans, y, x, ay, ax;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int fireCheck[1001][1001], manCheck[1001][1001];
char maze[1001][1001];

int main() {
  cin >> n >> m;
  queue<pair<int, int> > q;
  fill(&fireCheck[0][0], &fireCheck[0][0] + 1001 * 1001, 987654321);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> maze[i][j];
      if(maze[i][j] == 'F') {
        fireCheck[i][j] = 1;
        q.push(make_pair(i, j));
      }
      else if(maze[i][j] == 'J') {
        my = i; mx = j;
      }
    }
  }

  while(q.size()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || ny >= n || nx < 0 || nx >= m)
        continue;
      if(fireCheck[ny][nx] != INF || maze[ny][nx] == '#')
        continue;
      fireCheck[ny][nx] = fireCheck[y][x] + 1;
      q.push(make_pair(ny, nx));
    }
  }

  manCheck[my][mx] = 1;
  q.push(make_pair(my, mx));
  while(q.size()) {
    ay = q.front().first;
    ax = q.front().second;
    q.pop();
    if(ax == m - 1 || ay == n - 1 || ax == 0 || ay == 0) {
      ans = manCheck[ay][ax];
      break;
    }
    for(int i = 0; i < 4; i++) {
      int ny = ay + dy[i];
      int nx = ax + dx[i];
      if(ny < 0 || ny >= n || nx < 0 || nx >= m)
        continue;
      if(manCheck[ny][nx] || maze[ny][nx] == '#')
        continue;
      if(fireCheck[ny][nx] <= manCheck[ay][ax] + 1)
        continue;
      manCheck[ny][nx] = manCheck[ay][ax] + 1;
      q.push(make_pair(ny, nx));
    }
  }
  if(ans != 0)
    cout << ans << '\n';
  else
    cout << "IMPOSSIBLE \n";
  return 0;
}