#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, a[3], visited[61][61][61];
int path[6][3] = {
  {9, 3, 1},
  {9, 1, 3},
  {3, 1, 9},
  {3, 9, 1},
  {1, 9, 3},
  {1, 3, 9}
};
struct A {
  int a, b, c;
};
queue<A> q;
int solve(int a, int b, int c) {
  visited[a][b][c] = 1;
  q.push({a, b, c});
  while(q.size()) {
    int a = q.front().a;
    int b = q.front().b;
    int c = q.front().c;
    q.pop();
    if(visited[0][0][0])
      break;
    for(int i = 0; i < 6; i++) {
      int na = max(0, a - path[i][0]);
      int nb = max(0, b - path[i][1]);
      int nc = max(0, c - path[i][2]);
      if(visited[na][nb][nc])
        continue;
      visited[na][nb][nc] = visited[a][b][c] + 1;
      q.push({na, nb, nc});
    }
  }
  return visited[0][0][0] - 1;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << solve(a[0], a[1], a[2]);
  return 0;
}