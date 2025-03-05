#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
char treasure[51][51];
int n, m, mx = 0, visited[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<pair<int, int> > land;
void search(int x, int y) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      visited[i][j] = 0;
    }
  }
  visited[x][y] = 1;
  queue<pair<int, int > > q;
  q.push(make_pair(x, y));
  while(q.size() != 0) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])
        continue;
      if(treasure[nx][ny] == 'W')
        continue;
      q.push(make_pair(nx, ny));
      visited[nx][ny] = visited[x][y] + 1;
      mx = max(visited[nx][ny], mx);
    }
  }
  return;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> treasure[i][j];
      if(treasure[i][j] == 'L')
        land.push_back(make_pair(i, j));
    }
  }
  for(pair<int, int> a : land) {
      search(a.first, a.second);
    }
    cout << mx - 1;
  return 0;
}