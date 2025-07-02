#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, x, y, ret;
vector<pair<int, int> > v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  int l = v[0].first, r = v[0].second;
  for(int i = 1; i < v.size(); i++) {
    if(r >= v[i].first && r <= v[i].second)
      r = v[i].second;
    else if(r < v[i].first){
      ret += (r - l);
      l = v[i].first, r = v[i].second;
    }
  }
  ret += (r - l);
  cout << ret;
  return 0;
}