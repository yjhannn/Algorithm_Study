#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n, m, ans[10001], visited[10001];
vector<int> node[10001];
int dfs(int num) {
  visited[num] = 1;
  int ret = 1;
  for(int a : node[num]) {
    if(visited[a])
      continue;
    ret += dfs(a);
  }
  return ret;
}

int main() {
  cin >> n >> m;
  int a, b, max_val = 0;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    node[b].push_back(a);
  }
  for(int i = 0; i <= n; i++) {
    memset(visited, 0, sizeof(visited));
    ans[i] = dfs(i);
    max_val = max(ans[i], max_val);
  }
  for(int i = 1; i <= n; i++) {
    if(ans[i] == max_val)
      cout << i << " ";
  }
  return 0;
}