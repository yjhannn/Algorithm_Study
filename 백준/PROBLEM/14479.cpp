#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int visited[301][301];
char a[301][301];
int jx, jy, cx, cy, n, m, ret;
queue<pair<int, int> > q;
void dfs(int x, int y, int cnt) {
  visited[x][y] = cnt;
  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])
      continue;
    if(a[nx][ny] == '0') {
      dfs(nx, ny, cnt);
    }
    else {
      a[nx][ny] = '0';
      visited[nx][ny] = cnt;
      q.push(make_pair(nx, ny));
    }
  }
}
void bfs(int x, int y) {
  q.push(make_pair(x, y)) ;
  visited[x][y] = 1;
  while(a[cx - 1][cy - 1] != '0') {
    int ax = q.front().first;
    int ay = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++) {
      int nx = ax + dx[i];
      int ny = ay + dy[i];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])
        continue;
      if(a[nx][ny] == '0') {
        dfs(nx, ny, visited[ax][ay] + 1);
        if(visited[cx-1][cy-1])
          return;
      }
      else if(a[nx][ny] == '1'){
        q.push(make_pair(nx, ny));
        a[nx][ny] = '0';
        visited[nx][ny] = visited[ax][ay] + 1;
      }
      else if(a[nx][ny] == '#') {
        visited[nx][ny] = visited[ax][ay] + 1;
        a[nx][ny] = '0';
        
      }
    }
  }
  
}
int main() {
  cin >> n >> m;
  cin >> jx >> jy >> cx >> cy;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  bfs(jx - 1, jy - 1);
  cout << visited[cx - 1][cy - 1] - 1;
  return 0;
}