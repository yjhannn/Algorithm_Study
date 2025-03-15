//bfs
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, k, ret, visited[100001], cnt[100001];
vector<int> v;

void bfs() {
  queue<int> q;
  q.push(n);
  visited[n] = 1;
  cnt[n] = 1;
  while(!q.empty()) {
    int here = q.front();
    q.pop();
    if(here == k) {
      ret = visited[k];
      return;
    }
    for(int next : {here - 1, here + 1, here * 2}) {
      if(next >= 100001 || next < 0 || visited[next])
        continue;
      visited[next] = visited[here] + 1;
      cnt[next] = here;
      q.push(next);
    }
  }
  return;
}

int main() {
  cin >> n >> k;
  bfs();
  for(int i = k; i != n; i = cnt[i]) {
    v.push_back(i);
  }
  v.push_back(n);
  cout << ret - 1 << '\n';
  for(int i = v.size() - 1; i >= 0; i--)
    cout << v[i] << " ";
  return 0;
}