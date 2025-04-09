#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, x[50], y[50];

int solve(int i, int j, int k){
  int res = 0;
  for(int h=0; h<n; h++){
      res = max(res, min(min(abs(x[i]-x[h])+abs(y[i]-y[h]), abs(x[j]-x[h])+abs(y[j]-y[h])), 
                abs(x[k]-x[h])+abs(y[k]-y[h])));
  }
  return res;
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