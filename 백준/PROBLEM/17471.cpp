#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
using namespace std;
int n, num, num2, ret = 987654321, comp[11], visited[11], population[11];
vector<int> adj[11];

pair<int, int> dfs(int now, int val) {
  visited[now] = 1;
  pair<int, int> ret = make_pair(1, population[now]);
  for(int go : adj[now]) {
    if(comp[go] != val)
      continue;
    if(visited[go])
      continue;
    pair<int, int> tmp = dfs(go, val);
    ret.first += tmp.first;
    ret.second += tmp.second;
  }

  return ret;
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> population[i];
  }
  for(int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for(int j = 1; j <= k; j++) {
      cin >> num2;
      adj[i].push_back(num2);
      adj[num2].push_back(i);
    }
  }

  for(int i = 1; i < (1 << n) - 1; i++) {
    fill(comp, comp + 11, 0);
    fill(visited, visited + 11, 0);
    int x = -1, y = -1;
    for(int j = 0; j < n; j++) {
      if(i & (1 << j)) {
        comp[j+1] = 1;
        x = j + 1;
      }
      else  
        y = j + 1;
      // cout << comp[j+1] << " "; 
    }
    pair<int, int> c1 = dfs(x, 1);
    pair<int, int> c2 = dfs(y, 0);
    if(c1.first + c2.first == n)
      ret = min(ret, abs(c1.second - c2.second));
  }
  if(ret == 987654321)
    cout << -1;
  else
    cout << ret;

  return 0;
} 