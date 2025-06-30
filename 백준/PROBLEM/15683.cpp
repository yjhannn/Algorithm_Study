#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n, m, ret = 987654321, a[10][10];
vector<pair<int, int> > v;

vector<pair<int, int> > cctv(int here, int dir) {
  vector<pair<int, int> > _v;
  int x = v[here].first;
  int y = v[here].second;
  if(a[x][y] == 1) {
    while(1) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != 6) {
        if(a[nx][ny] == 0) {
          a[nx][ny] = 9;
          _v.push_back(make_pair(nx, ny));
        }
        x = nx, y = ny;
      }
      else
        break;
    }
  }
  else if(a[x][y] == 2) {
    for(int i = 0; i <= 2; i+=2) {
      int _x = x;
      int _y = y;
      while(1) {
        int nx = _x + dx[(dir + i) % 4];
        int ny = _y + dy[(dir + i) % 4];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != 6) {
          if(a[nx][ny] == 0) {
            a[nx][ny] = 9;
            _v.push_back(make_pair(nx, ny));
          }
          _x = nx, _y = ny;
        }
        else 
           break;
      }
    }
  }
  else if(a[x][y] == 3) {
    for(int i = 0; i < 2; i++) {
      int _x = x;
      int _y = y;
      while(1) {
        int nx = _x + dx[(dir + i) % 4];
        int ny = _y + dy[(dir + i) % 4];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != 6) {
          if(a[nx][ny] == 0) {
            a[nx][ny] = 9;
            _v.push_back(make_pair(nx, ny));
          }
          _x = nx, _y = ny;
        }
        else
          break;
      }
    }
  }
  else if(a[x][y] == 4) {
    for(int i = 0; i < 3; i++) {
      int _x = x;
      int _y = y;
      while(1) {
        int nx = _x + dx[(dir + i) % 4];
        int ny = _y + dy[(dir + i) % 4];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != 6) {
          if(a[nx][ny] == 0) {
            a[nx][ny] = 9;
            _v.push_back(make_pair(nx, ny));
          }
          _x = nx, _y = ny;
        }
        else
          break;
      }
    }
  }
  else if(a[x][y] == 5) {
    for(int i = 0; i < 4; i++) {
      int _x = x;
      int _y = y;
      while(1) {
        int nx = _x + dx[(dir + i) % 4];
        int ny = _y + dy[(dir + i) % 4];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != 6) {
          if(a[nx][ny] == 0) {
            a[nx][ny] = 9;
            _v.push_back(make_pair(nx, ny));
          }
          _x = nx, _y = ny;
        }
        else
          break;
      }
    }
  }
  return _v;
}

void dfs(int here) {
  if(here == v.size()) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(a[i][j] == 0)
          cnt++;
      }
    }
    ret = min(cnt, ret);
    return;
  }
  for(int i = 0; i < 4; i++) {
    vector<pair<int, int> > _v = cctv(here, i);
    dfs(here + 1);
    for (auto b : _v)
      a[b.first][b.second] = 0;
  }
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
      if(a[i][j] != 0 && a[i][j] != 6) {
        v.push_back(make_pair(i, j));
      }
    }
  }
  dfs(0);
  cout << ret;
  return 0;
}