#include <iostream>
using namespace std;
int n, ret, dp[17][17][3], map[17][17];

bool check(int x, int y, int d) {
  if(d == 0 || d == 2) {
    if(map[x][y] == 0)
      return true;
  }
  else if(d == 1) {
    if(map[x][y] == 0 && map[x-1][y] == 0 && map[x][y-1] == 0)
      return true;
  }
  return false;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }
  dp[0][1][0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(check(i, j + 1, 0))
        dp[i][j+1][0] += dp[i][j][0];
      if(check(i+1, j+1, 1))
        dp[i+1][j+1][1] += dp[i][j][0];
      if(check(i+1,j,2))
        dp[i+1][j][2] += dp[i][j][2];
      if(check(i+1, j+1, 1))
        dp[i+1][j+1][1] += dp[i][j][2];
      if(check(i, j+1, 0))
        dp[i][j+1][0] += dp[i][j][1];
      if(check(i+1, j+1, 1))
        dp[i+1][j+1][1] += dp[i][j][1];
      if(check(i+1, j, 2))
        dp[i+1][j][2] += dp[i][j][1];
    }
  }
  ret += (dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2]);
  cout << ret;
  return 0;
}