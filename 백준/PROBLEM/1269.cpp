#include <iostream>
#include <map>
using namespace std;
map<int, bool> mp;

int main() {
  int n, m, num;
  cin >> n >> m;
  int a[n], b[m];
  for(int i = 0; i < n+m; i++) {
    cin >> num;
    if(mp[num] == true)
      mp.erase(num);
    else
      mp[num] = true;
  }
  cout << mp.size();
  return 0;
}