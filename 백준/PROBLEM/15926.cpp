#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
int n, cnt, ans, a[200001];
string s;
stack<int> stk;
int main() {
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    if(s[i] == '(') {
      stk.push(i);
    }
    else if(stk.size()) {
      a[i] = a[stk.top()] = 1;
      stk.pop();
    }
  }
  for(int i = 0; i < n; i++) {
    if(a[i]) {
      cnt++;
      ans = max(ans, cnt);
    }
    else
      cnt = 0;
  }
  cout << ans;
  return 0;
}