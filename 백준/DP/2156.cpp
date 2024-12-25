// DP
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  int grape[10001];
  int dp[10001];

  for(int i = 1; i <= n; i++) {
    cin >> grape[i];
  }

  dp[0] = 0;
  dp[1] = grape[1];
  dp[2] = grape[1] + grape[2];

  for(int i = 3; i <= n; i++) {
    dp[i] = max({dp[i-3]+grape[i-1]+grape[i], dp[i-2]+grape[i], dp[i-1]});
  }

  cout << dp[n] <<'\n';
  
  return 0;
}