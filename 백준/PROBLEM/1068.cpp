// Vector를 이용한 트리
#include <iostream>
#include <vector>
using namespace std;
vector<int> t[52];
int visited[52];
int n, ans, delNum;
int dfs(int num) {
  int cnt = 0;
  int child = 0;
  for(int a : t[num]) {
    if(a == delNum)
      continue;
    cnt += dfs(a);
    child++;
  }
  if(child == 0)
    cnt += 1;
  return cnt;
}

int main() {
  cin >> n;
  int parent, root;
  for(int i = 0; i < n; i++) {
    cin >> parent;
    if(parent == -1)
      root = i;
    else
      t[parent].push_back(i);
  }
  cin >> delNum;
  if(root == delNum) {
    cout << '0' << '\n';
    return 0;
  }
  cout << dfs(root) << '\n';
  return 0;
}
