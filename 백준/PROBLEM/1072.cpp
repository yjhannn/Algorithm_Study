#include <iostream>
using namespace std;
typedef long long ll;
ll x, y, ret = -1;
int target;

bool check(int mid) {
  ll a = x + mid, b = y + mid;
  int per = (b * 100) / a;
  if(per == target) 
    return true;
  else
    return false;
}

int main() {
  cin >> x >> y;
  if(x == y) {
    cout << -1;
    return 0;
  }
  target = (100 * y) / x; 
  ll low = 1, high = 1e9;
  while(low <= high) {
    ll mid = (low + high) / 2;
    if(check(mid)) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
      ret = mid;
    }
  }
  cout << ret;
  return 0;
}