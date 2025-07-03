#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m, ret;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  vector<ll> pSum(n+1), modNum(m);
  for(int i = 1; i <= n; i++) {
    ll a;
    cin >> a;
    pSum[i] = (pSum[i-1] + a) % m;
    modNum[pSum[i]]++;
  }
  for(int i = 0; i < m; i++) {
    ret += (modNum[i] * (modNum[i] - 1)) / 2;
  }
  ret += modNum[0];
  cout << ret;

  return 0;
}