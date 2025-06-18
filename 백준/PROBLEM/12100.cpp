// 2048: 백트래킹 + 구현
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, ret, a[21][21];

int check_max() {
  int mx = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      mx = max(mx, a[i][j]);
  return mx;
}

// 90도 시계방향 회전
void rotate() {
  int tmp[21][21];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      tmp[i][j] = a[n - j - 1][i];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      a[i][j] = tmp[i][j];
}

// dir: 0=좌, 1=상, 2=우, 3=하
void move(int dir) {
  // dir번 만큼 90도 회전하여 항상 왼쪽으로만 이동 처리
  for(int i = 0; i < dir; i++) rotate();
  // 왼쪽으로 이동
  for(int i = 0; i < n; i++) {
    queue<int> q;
    for(int j = 0; j < n; j++) {
      if(a[i][j]) {
        q.push(a[i][j]);
        a[i][j] = 0;
      }
    }
    int idx = 0;
    // 1. 압축 + 2. 합치기
    while(!q.empty()) {
      int val = q.front(); q.pop();
      if(!q.empty() && q.front() == val) {
        val *= 2;
        q.pop();
      }
      a[i][idx++] = val;
    }
  }
  // 원래 방향으로 복원
  for(int i = 0; i < (4 - dir) % 4; i++) rotate();
}

void dfs(int depth) {
  if(depth == 5) {
    ret = max(ret, check_max());
    return;
  }
  int backup[21][21];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      backup[i][j] = a[i][j];
  for(int d = 0; d < 4; d++) {
    move(d);
    dfs(depth + 1);
    // 복원
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        a[i][j] = backup[i][j];
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> a[i][j];
  dfs(0);
  cout << ret << '\n';
  return 0;
}