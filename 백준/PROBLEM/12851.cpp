//bfs
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, k, visited[100001], cnt[100001];

void bfs() {
  queue<int> q;
  q.push(n);
  visited[n] = 1;
  cnt[n] = 1;
  while(!q.empty()) {
    int here = q.front();
    q.pop();
    for(int next : {here - 1, here + 1, here * 2}) {
      if(next < 0 || next > 100000)
        continue;
      if(!visited[next]) {
        visited[next] = visited[here] + 1;
        cnt[next] = cnt[here];
        q.push(next);
      }
      else if(visited[next] == visited[here] + 1) {
        cnt[next] += cnt[here];
      }
    }
  }
}

int main() {
  cin >> n >> k;
  bfs();
  cout << visited[k] - 1 << '\n' << cnt[k];
  return 0;
} 