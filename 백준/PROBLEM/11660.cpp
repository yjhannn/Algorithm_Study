#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int matrix[n+1][n+1];
  int psum[n+1][n+1];
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      matrix[i][j] = 0;
      psum[i][j] = 0;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> matrix[i][j];
      if(j == 1)
        psum[i][j] = matrix[i][j];
      else
        psum[i][j] = matrix[i][j] + psum[i][j-1];
    }
  }

  int a, b, c, d;
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c >> d;
    int ans = 0;
    int sum = 0;
    for(int i = a; i <= c; i++) {
      if(b == 1)
        sum = psum[i][d];
      else
        sum = psum[i][d] - psum[i][b-1];
      ans += sum;
    }
    cout << ans << '\n';
  }
  
  return 0;
}