#include <iostream>
#include <algorithm>
using namespace std;
int m, n, fans, sans, tans, a[51][51], visited[51][51], csize[2504];
const int dy[] = {0, -1, 0, 1}; 
const int dx[] = {-1, 0, 1, 0}; 

int dfs(int y, int x, int cnt){
    if(visited[y][x]) return 0; 
    visited[y][x] = cnt; 
    int ret = 1; 
    for(int i = 0; i < 4; i++){
        if(!(a[y][x] & (1 << i))){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            ret += dfs(ny, nx, cnt); 
        } 
    } 
    return ret; 
}

int main() {
  cin >> m >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(!visited[i][j]) {
        fans++;
        csize[fans] = dfs(i, j, fans);
        sans = max(sans, csize[fans]);
      }
    }
  }

  // 3번 문제
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(i + 1 < n) {
        int a = visited[i+1][j];
        int b = visited[i][j];
        if(a != b) {
          tans = max(tans, csize[a] + csize[b]);
        }
      }
      if(j + 1 < m) {
        int a = visited[i][j+1];
        int b = visited[i][j];
        if(a != b) {
          tans = max(tans, csize[a] + csize[b]);
        }
      }
    }
  }

  cout << fans << '\n' << sans << '\n' << tans;
  return 0;
}