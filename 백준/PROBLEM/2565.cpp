#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, b, ret, pos[501];
vector<pair<int, int> > v;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++) {
    auto it = lower_bound(pos, pos + ret, v[i].second);
    if(*it == 0) 
      ret++;  
    *it = v[i].second;
  }
  cout << n - ret;
  return 0;
}