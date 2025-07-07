#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, ret, sum, mx, a[100001];

bool check(int val) {
  if(mx > val)
    return false;
  int tmp = val;
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(val - a[i] < 0) {
      val = tmp;
      cnt++;
    }
    val -= a[i];
  }
  if(val != tmp)
    cnt++;
  if(cnt <= m)
    return true;
  else
    return false;
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }
  int st = 0, en = sum;
  while(st <= en) {
    int mid = (st + en) / 2;
    if(check(mid)) {
      en = mid - 1;
      ret = mid;
    }
    else 
      st = mid + 1;
  }
  cout << ret;
  return 0;
}