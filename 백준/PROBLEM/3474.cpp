#include <iostream>
using namespace std;
typedef long long ll;
ll solve(int n) {
  ll second = 0, fifth = 0;
  for(int i = 2; i <= n; i *= 2) {
    second += n/i;
  }
  for(int i = 5; i <= n; i *= 5) {
    fifth += n/i;
  }
  if(second > fifth)
    return fifth;
  else
    return second;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
  int t;
  ll n;
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n;
    cout << solve(n) << '\n';
  }
  return 0;
}