#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int k, check[10];
vector<string> ans;
char a[10];

bool chk(char x, char y, char op) {
  if(x < y && op == '<') return true;
  if(x > y && op == '>') return true;
  return false;
}

void dfs(int here, string num) {
  if(here == k + 1) {
    ans.push_back(num);
    return;
  }
  for(int i = 0; i < 10; i++) {
    if(check[i])
      continue;
    if(here == 0 || chk(num[here - 1], i + '0', a[here - 1])) {
      check[i] = 1;
      dfs(here + 1, num + to_string(i));
      check[i] = 0;
    }
  }
}

int main() {
  cin >> k;
  for(int i = 0; i < k; i++) {
    cin >> a[i];
  }
  dfs(0, "");
  sort(ans.begin(), ans.end());
  cout << ans[ans.size()-1] << '\n' << ans[0];
  return 0;
}