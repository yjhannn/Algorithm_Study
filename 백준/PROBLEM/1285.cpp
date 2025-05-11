#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, ans = 987654321, a[41];
string str;

void solve(int now) {
  if(now == n + 1) {
    int sum = 0;
    for(int i = 1; i <= (1 << (n - 1)); i *= 2) {
      int cnt = 0;
      for(int j = 1; j <= n; j++) {
        if(a[j] & i)
          cnt++;
      }
      sum += min(cnt, n - cnt);
    }
    ans = min(ans, sum);
    return;
  }
  solve(now + 1);
  a[now] = ~a[now];
  solve(now + 1);
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> str;
    int val = 1;
    for(int j = 0; j < str.length(); j++) {
      if(str[j] == 'T')
        a[i] |= val;
      val *= 2;
    }
  }
  solve(1);
  cout << ans;
  return 0;
}