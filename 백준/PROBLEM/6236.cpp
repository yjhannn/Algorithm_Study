#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, mx, sum, a[100001];

bool check(int mid) {
  int tmp = mid;
  int cnt = 1;
  for(int i = 0; i < n; i++) {
    if(a[i] > mid) return false;
    if(tmp < a[i]) {
      cnt++;
      tmp = mid;
    }
    tmp -= a[i];
  }
  return m >= cnt;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }
  int st = mx, en = sum;
  while(st <= en) {
    int mid = (st + en) / 2;
    if(check(mid)) {
      k = mid;
      en = mid - 1;
    }
    else
      st = mid + 1;
  }
  cout << k;
  return 0;
}