#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n;
    map<string, int> m;
    for(int i = 0; i < n; i++) {
      string name, wear;
      cin >> name >> wear;
      if(m.find(wear) == m.end())
        m.insert({wear, 1});
      else
        m[wear]++;
    }
    int ans = 1;
    for(auto i : m) {
      ans *= (i.second + 1);
    }
    ans -= 1;
    cout << ans << '\n';
  }

  return 0;
}