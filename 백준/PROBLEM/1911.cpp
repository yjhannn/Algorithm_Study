#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, l, ret;
vector<pair<int, int> > v;
int main() {
  cin >> n >> l;
  for(int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    v.push_back(make_pair(start, end));
  }
  sort(v.begin(), v.end());
  int s = v[0].first, e = v[0].first + l;
  for(int i = 0; i < v.size(); i++) {
    if(s < v[i].first) {
      s = v[i].first;
      e = v[i].first + l;
    }
    while(s < v[i].second) {
      ret++;
      s += l;
      e += l;
    }
  }
  cout << ret;
  return 0;
}