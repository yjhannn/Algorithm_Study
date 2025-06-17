#include <iostream>
#include <vector>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int r, c, t, a[51][51], b[51][51], ret;
vector<pair<int, int> > dust;
vector<int> clean;
void total() {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(a[i][j] <= 0)
        continue;
      ret += a[i][j];
    }
  }
}

void cleaner(int num) {
  int row = clean[num];
  int i = 0;
  pair<int, int> now = make_pair(row, 1);
  vector<pair<int, int>> endpoint;
  endpoint.push_back({row, c-1});
  endpoint.push_back({0, c-1});
  endpoint.push_back({r-1, c-1});
  endpoint.push_back({r-1, 0});
  endpoint.push_back({0, 0});

  int pre = 0, tmp = 0;
  while(now.second != 0 || now.first != row) {
    tmp = a[now.first][now.second];
    a[now.first][now.second] = pre;
    pre = tmp;

    for(pair<int, int> n : endpoint) {
      if(now == n) {
        num == 0 ? i = (i+3) % 4 : i = (i + 1) % 4;
      }
    }
    now.second += dx[i];
    now.first += dy[i];
  }
}

void dusty() {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(a[i][j] <= 0)
        continue;
      int cnt = 0;
      for(int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c 
        || a[nx][ny] == -1)
          continue;
        cnt++;
        b[nx][ny] += (a[i][j] / 5);
      }
      b[i][j] -= ((a[i][j] / 5) * cnt);
    }
  }
}

int main() {
  cin >> r >> c >> t;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> a[i][j];
      if(a[i][j] == -1) {
        clean.push_back(i);
      }
      else if(a[i][j] != 0) {
        dust.push_back(make_pair(i, j));
      }
    }
  }

  while(t--) {
    dusty();
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        a[i][j] += b[i][j];
        b[i][j] = 0;
      }
    }
    cleaner(0);
    cleaner(1);
  }
  total();
  cout << ret;
  return 0;
}