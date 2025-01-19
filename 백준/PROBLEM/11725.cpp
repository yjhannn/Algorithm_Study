#include <iostream>
#include <vector>
using namespace std;
vector<int> tree[100001];
bool visited[100001];
int ans[100001];
void dfs(int node) {
  visited[node] = true;
  for(int i = 0; i < tree[node].size(); i++) {
    int child = tree[node][i];
    if(!visited[child]) {
      ans[child] = node;
      dfs(child);
    }
  }
}

int main() {
  int n;
  int a, b;
  cin >> n;
  for(int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  dfs(1);
  for(int i = 2; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}