#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, ret = 987654321, a[300001];

bool check(ll num) {
  ll cnt = 0;
  for(int i = 0; i < m; i++) {
    cnt += (a[i] / num);
    if(a[i] % num) cnt++;
  }
  if(n >= cnt)
    return true;
  else
    return false;
}

int main() {
  cin >> n >> m;
  ll low = 1, high = 0, mid;
  for(int i = 0; i < m; i++) {
    cin >> a[i];
    high = max(high, a[i]);
  }

  while(low <= high) {
    mid = (low + high) / 2;
    if(check(mid)) {
      ret = min(ret, mid);
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  cout << ret;
  return 0;
}