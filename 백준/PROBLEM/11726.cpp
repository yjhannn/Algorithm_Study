#include <iostream>

using namespace std;
int n;
int dp[1002];

int main() {
  cin >> n;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  for(int i = 4; i <= n; i++) {
    dp[i] = (dp[i-1] + dp[i-2]) % 10007; // 분배법칙에 의해 가능함.
  }
  cout << dp[n];
}