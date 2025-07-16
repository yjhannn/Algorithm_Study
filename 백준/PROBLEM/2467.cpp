#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, ret = 2e9, a[100001];
pair<ll, ll> v;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll left = 0, right = n - 1;
  while(left < right) {
    ll sum = a[left] + a[right];
    if(abs(ret) > abs(sum)) {
      ret = sum;
      v = make_pair(a[left], a[right]);
    }

    if(sum < 0) left++; // 합이 음수면 더 큰 수 필요
    else right--;   
  }
  cout << v.first << " " << v.second;
  return 0;
}