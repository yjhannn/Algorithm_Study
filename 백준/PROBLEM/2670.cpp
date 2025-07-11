#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip> // 소수 n번째 자리에서 반올림
using namespace std;
int n;
double a[10001], dp[10001], ret =-987654321;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0] = a[0];
  for(int i = 1; i < n; i++) {
    dp[i] = max(a[i], dp[i-1] * a[i]);
    ret = max(ret, dp[i]);
  }

  // 소수 n번째 자리에서 반올림
  cout << fixed << setprecision(3) << ret << '\n';
  return 0;
}