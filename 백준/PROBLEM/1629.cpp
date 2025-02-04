#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, c;

ll solve(ll a, ll b) {
  if(b == 1)
    return a % c;
  ll ret = solve(a, b/2);
  ret = (ret * ret) % c;
  if(b%2 != 0)
    ret = (ret * a) % c;
  return ret;
}

int main() {
  cin >> a >> b >> c;
  cout << solve(a, b);
  return 0;
}