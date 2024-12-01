// DP
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  int tri[501][501];
  int dp[501][501];
  for(int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> tri[i][j];
    }
  }

  dp[1][1] = tri[1][1];

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
    }
  }

  int ans = -1;
  for (int i = 1; i <= n; i++) {
    if(ans < dp[n][i])
      ans = dp[n][i];
  }
  cout << ans << '\n';

  return 0;
}