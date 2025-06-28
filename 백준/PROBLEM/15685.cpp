#include <iostream>
#include <vector>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int n, ret, visited[101][101];

void check() {
  for(int i = 0; i < 101; i++) {
    for(int j = 0; j < 101; j++) {
      if(visited[i][j] == 1 && visited[i+1][j] == 1 &&
      visited[i][j+1] == 1 && visited[i+1][j+1] == 1)
        ret++;
    }
  }
}

void solve(int x, int y, int d, int g) {
  vector<int> dirs;
  dirs.push_back(d);

  for(int i = 1; i <= g; i++) {
    int size = dirs.size();
    for(int j = size - 1; j >= 0; j--) {
      dirs.push_back((dirs[j] + 1) % 4);
    }
  }

  visited[x][y] = 1;
  for(int dir : dirs) {
    x += dx[dir];
    y += dy[dir];
    if(x >= 0 && x < 101 && y >= 0 && y < 101)
      visited[x][y] = 1;
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y, d, g;
    cin >> x >> y >> d >> g;
    solve(x, y, d, g);
  }
  check();
  cout << ret;
  return 0;
}