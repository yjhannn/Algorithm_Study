#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, u, v, ret = 987654321, visited[101];
vector<int> mv[101];

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> u >> v;
    mv[u].push_back(v);
  }
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    mv[u].push_back(v);
  }
  queue<pair<int, int> > q;
  q.push(make_pair(1, 0));
  visited[1] = 1;

  while(!q.empty()) {
    int here = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if(here == 100) {
      cout << cnt;
      return 0;
    }
    for(int i = 1; i <= 6; i++) {
      int next = here + i;
      if(next > 100)
        continue;
      if(mv[next].size() >= 1) {
        next = mv[next][0];
        if(!visited[next]) {
          visited[next] = 1;
          q.push(make_pair(next, cnt + 1));
        }
      }
      else {
        if(!visited[next]) {
          visited[next] = 1;
          q.push(make_pair(next, cnt + 1));
        }
      }
    }
  }
  return 0;
}