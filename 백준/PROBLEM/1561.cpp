#include <iostream>
#define max_n 60000000001
#define max_m 10001
using namespace std;
typedef long long ll;
ll n, m, a[max_m], ret, temp;

bool check(ll mid) {
  temp = m;
  for(ll i = 0; i < m; i++)
    temp += (mid / a[i]);
  return temp >= n;
}

int main() {
  cin >> n >> m;
  for(ll i = 0; i < m; i++) {
    cin >> a[i];
  }
  if(n <= m) {
    cout << n;
    return 0;
  }
  ll low = 0, high = max_n;
  while(low <= high) {
    ll mid = (low + high) / 2;
    if(check(mid)) {
      high = mid - 1;
      ret = mid;
    }
    else
      low = mid + 1;
  }
  temp = m;
  for(ll i = 0; i < m; i++) {
    temp += ((ret - 1) / a[i]);
  }
  for(ll i = 0; i < m; i++) {
    if(ret % a[i] == 0) 
      temp++;
    if(temp == n) {
      cout << i + 1;
      return 0;
    }
  }
  return 0;
}