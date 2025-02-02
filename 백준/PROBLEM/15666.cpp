#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int first[9];
int value[9];
int n, m;
set<vector<int> > s;
void dfs(int num, int now) {
  if(now == m) {
    vector<int> v;
    for(int i = 0; i < m; i++) {
      v.push_back(value[i]);
    }
    s.insert(v);
    v.clear();
  }
  else {
    for(int i = num; i < n; i++) {
      value[now] = first[i];
      dfs(i, now+1);
    }

  }
}
int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> first[i];
  }
  sort(first, first+n);
  dfs(0,0);
  for(auto vector : s) {
    for(auto temp : vector) {
      cout << temp << " ";
    }
    cout << '\n';
  }

}