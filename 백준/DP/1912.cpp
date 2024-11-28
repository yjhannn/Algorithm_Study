// DP
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int num[100001];
  int dp[100001] = {0, };

  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++) {
    cin >> num[i];
    dp[i] = num[i];
  }

  int ans = dp[0];
  for (int i = 1; i < n;i ++) {
    dp[i] = max(num[i], dp[i-1]+num[i]);
    if(ans < dp[i])
      ans = dp[i];
  }

  cout << ans << '\n';

  return 0;
}