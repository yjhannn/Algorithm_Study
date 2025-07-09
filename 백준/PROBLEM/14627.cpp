#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, sum, ret, min_val = 1e9, v[1000001];

bool check(ll num) {
  ll cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt += (v[i] / num) ;
  }
  return cnt >= m;
}

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  ll low = 1, high = 1e9;
  while(low <= high) {
    ll mid = (low + high) / (1LL * 2);
    if(check(mid)) {
      low = mid + 1;
      ret = mid;
    }
    else
      high = mid - 1;
  }
  cout << sum - ret * m;
  return 0;
}