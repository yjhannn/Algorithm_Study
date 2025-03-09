#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, l, r, val, sum, a[51][51], b[51][51], visited[51][51];
vector<pair<int, int> > v;
void solve(int x, int y) {

  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
      continue;
    val = abs(a[x][y] - a[nx][ny]);
    if(val >= l && val <= r) {
      sum += a[nx][ny];
      v.push_back(make_pair(nx, ny));
      visited[nx][ny] = 1;
      solve(nx, ny);
    }
  }
}
int main() {
  cin >> n >> l >> r;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int day = 0;
  while(1) {
    bool check = 0;
    int avg = 0;
    fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(!visited[i][j]) {
          v.clear();
          visited[i][j] = 1;
          v.push_back(make_pair(i, j));
          sum = a[i][j];
          solve(i, j);
          if(v.size() == 1)
            continue;
          for(pair<int, int> p : v) {
            a[p.first][p.second] = sum / v.size();
            check = 1;
          }
        }
      }
    }
    if(check == 0)
      break;
    day++;
  }
  cout << day;
  return 0;
}