#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, a[1001][1001], visited[1001][1001];
int goal_x, goal_y;
void bfs() {
  queue<pair<int, int> > q;
  q.push(make_pair(goal_x, goal_y));
  while (!q.empty())
  {
    int ax = q.front().first;
    int ay = q.front().second;

    q.pop();
    for(int i = 0; i < 4; i++) {
      int nx = ax + dx[i];
      int ny = ay + dy[i];

      if(a[nx][ny] == 1 && visited[nx][ny] == 0) {
        visited[nx][ny] = visited[ax][ay] + 1;
        q.push(make_pair(nx, ny));
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i][j] == 1 && visited[i][j] == 0) {
        visited[i][j] = -1;
      }
    }
  }
  
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
      if(a[i][j] == 2) {
        goal_x = i;
        goal_y = j;
      }
    }
  }
  visited[goal_x][goal_y] = 0;
  bfs();
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << visited[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}