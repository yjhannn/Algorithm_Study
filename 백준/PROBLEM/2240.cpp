#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t, w, dp[1003][2][32], a[1003];

int solve(int i, int tree, int cnt) {
  if(cnt < 0)
    return -987654321;
  if(i == t)
    return 0;
  int &ret = dp[i][tree][cnt];
  if(~ret)
    return ret;
  return ret = max(solve(i + 1, tree^1, cnt - 1), solve(i + 1, tree, cnt)) + (tree == a[i] - 1);
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> t >> w;
  for(int i = 0; i < t; i++) {
    cin >> a[i];
  }
  cout << max(solve(0, 0, w), solve(0, 1, w - 1));
  return 0;
}