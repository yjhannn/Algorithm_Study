#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, val;
vector<ll> v, lis, idx;

int main() {
  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> val;
    v.push_back(val);
    if(lis.empty() || lis.back() < val) {
      lis.push_back(val);
      idx.push_back(lis.size() - 1);
    }
    else {
      auto lowerPos = lower_bound(lis.begin(), lis.end(),val);
      *lowerPos = val;
      idx.push_back(lowerPos - lis.begin());
    }
  }
  int len = lis.size();
  vector<ll> ans(len);
  cout << len << '\n';
  for(int i = n - 1; i >= 0; i--) {
    if(idx[i] == len - 1) {
      ans[len - 1] = v[i];
      len--;
    }
  }
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}