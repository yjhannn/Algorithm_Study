// DP
#include <iostream>

using namespace std;

int ans[21][21][21];

int dp(int a, int b, int c) {
  
  if(a <= 0 || b <= 0 || c <= 0) 
    return 1;
  if (a > 20 || b > 20 || c > 20)
    return dp(20,20,20);
  if(ans[a][b][c])
    return ans[a][b][c];
  if (a < b && b < c) {
    ans[a][b][c] = dp(a, b, c-1) + dp(a, b-1, c-1) - dp(a, b-1, c);
    return ans[a][b][c];
  }
  ans[a][b][c] = dp(a-1, b, c) + dp(a-1, b-1, c) + dp(a-1, b, c-1) -dp(a-1, b-1, c-1);
  return ans[a][b][c];
  
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c;
  while(1) {
    cin >> a >> b >> c;
    if(a == -1 && b == -1 && c == -1)
      break;
    cout << "w(" << a << ", " << b << ", " << c << ") = " << dp(a, b, c) << '\n';
  }

  return 0;
}
