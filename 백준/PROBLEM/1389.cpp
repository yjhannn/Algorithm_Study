#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[102];
int a, b;
int levelCount = 0;

void bfs(int n, int m, bool visit[102]) {
  queue<pair<int, int> > q;
  q.push(make_pair(n, 0));
  visit[n] = true;
  while(!q.empty()) {
    int x = q.front().first;
    int cnt = q.front().second;
    q.pop();
    if(x == m) {
      levelCount = cnt;
      break;
    }

    for (int i = 0; i < v[x].size(); i++) {
      if(!visit[v[x][i]]) {
        q.push(make_pair(v[x][i], cnt + 1));
        visit[v[x][i]] = true;
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int result = 99999999;
  int num;
  for (int i = 1; i <= n; i++) {
    int level = 0;
    for (int j = 1; j <= n; j++) {
      bool visit[102] = {0, };
      if(i == j)
        continue;
      bfs(i, j, visit);
      level += levelCount;
      levelCount = 0;
    }
    if(result > level) {
      result = level;
      num = i;
    }
  }

  cout << num << '\n';
  return 0;
}