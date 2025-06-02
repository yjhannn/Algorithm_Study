#include <iostream>
#include <stack>
#include <utility>
using namespace std;
typedef long long ll;
ll n, ans, temp;
stack<pair<ll, ll> > s;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    int cnt = 1;
    while(s.size() && s.top().first <= temp) {
      ans += s.top().second;
      if(s.top().first == temp) {
        cnt = s.top().second + 1;
      }
      else 
        cnt = 1;
      s.pop();
    }
    if(s.size())
      ans++;
    s.push(make_pair(temp, cnt));
  }

  cout << ans;
  return 0;
}