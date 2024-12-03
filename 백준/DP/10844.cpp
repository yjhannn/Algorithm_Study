// DP
#include <iostream>
#include <cmath>
#define mod 1000000000
using namespace std;

int main() {
  int n;
  int dp[101][101];
  cin >> n;

  for (int i = 1; i < 10; i++) {
    dp[1][i] = 1;      
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      if(j == 0)
        dp[i][j] = dp[i-1][j+1];
      else if(j == 9)
        dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
      dp[i][j] %= mod;
    }
  }

  int ans = 0;
  for (int i = 0; i < 10; i++) {
    ans = (ans + dp[n][i]) % mod;
  }

  cout << ans << '\n';

  return 0;
}