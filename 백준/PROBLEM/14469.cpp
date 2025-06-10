#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, arv, dur, cur;
vector<pair<int, int> > v;
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arv >> dur;
    v.push_back(make_pair(arv, dur));
  }
  sort(v.begin(), v.end());
  cur = 0;
  for(int i = 0; i < n; i++) {
    if(cur < v[i].first)
      cur = v[i].first;
    cur += v[i].second;
  }
  cout << cur;
  return 0;
}