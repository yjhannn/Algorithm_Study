#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, x[50], y[50];

int solve(int a, int b, int c) {
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt = max(cnt, min(min(abs(x[a] - x[i]) + abs(y[a] - y[i]), abs(x[b] - x[i]) 
    + abs(y[b] - y[i]), abs(x[c] - x[i]) + abs(y[c] - y[i]))));
  }
  return cnt;
}

int main() {
  int ret = 200001;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  if(k == 1) {
    for(int i = 0; i < n; i++) {
      ret = min(ret, solve(i, i, i));
    }
  }
  else if(k == 2) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        ret = min(ret, solve(i, j, j));
      }
    }
  }
  else if(k == 3) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
          ret = min(ret, solve(i, j, k));
        }
      }
    }
  }
  cout << ret;
  return 0;
}