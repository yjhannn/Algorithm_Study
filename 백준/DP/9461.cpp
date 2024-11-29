// DP
#include <iostream>

using namespace std;
long long ans[101] = {0, 1, 1, };
long long dp(int n) {
  if(n < 3)
    return ans[n];
  if(ans[n] == 0)
    ans[n] = dp(n-2) + dp(n-3);
  return ans[n];
  
}
int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c;
  int T, n;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n;
    cout << dp(n) << '\n';
  }
  
  return 0;
}