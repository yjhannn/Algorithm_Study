#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int mp, mf, ms, mv;
int p, f, s, v, c, ret = 987654321;
map<int, vector<vector<int> > > m;
struct A {
  int mp, mf, ms, mv, cost;
}a[16];
int main() {
  int n;
  cin >> n;
  cin >> mp >> mf >> ms >> mv;
  for(int i = 0; i < n; i++) {
    cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
  }
  for(int i = 1; i < (1 << n); i++) {
    p = 0, f = 0, s = 0, v = 0, c = 0;
    vector<int> vec;
    for(int j = 0; j < n; j++) {
      if(i & (1 << j)) {
        vec.push_back(j + 1);
        p += a[j].mp;
        f += a[j].mf;
        s += a[j].ms;
        v += a[j].mv;
        c += a[j].cost;
      }
    }
    if(p >= mp && f >= mf && s >= ms && v >= mv) {
      if(ret >= c) {
        ret = c;
        m[ret].push_back(vec);
      }
    }
  }
  if(ret == 987654321)
    cout << -1 << '\n';
  else {
    sort(m[ret].begin(), m[ret].end());
    cout << ret << '\n';
    for(int a : m[ret][0]) {
      cout << a << " ";
    }
  }
  return 0;
}