#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> sum;
int n, m, ans, a[5][5];

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%1d", &a[i][j]);
    }
  }
  for(int tot = 0; tot < (1 << (n*m)); tot++) {
    int sum = 0;
    // 가로(0)
    for(int i = 0; i < n; i++) {
      int val = 0;
      for(int j = 0; j < m; j++) {
        int k = i * m + j;
        if((tot & (1 << k)) == 0) {
          val = val * 10 + a[i][j];
        }
        else {
          sum += val;
          val = 0;
        }
      }
      sum += val;
    }
    // 세로(1)
    for(int j = 0; j < m; j++) {
      int val = 0;
      for(int i = 0; i < n; i++) {
        int k = i * m + j;
        if((tot & (1 << k)) != 0) {
          val = val * 10 + a[i][j];
        }
        else {
          sum += val;
          val = 0;
        }
      }
      sum += val;
    }
    ans = max(ans, sum);
  }

  cout << ans;
  return 0;
}