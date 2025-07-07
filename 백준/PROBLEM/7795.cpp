#include <iostream>
#include <algorithm>
using namespace std;
int t, n, m, ret, a[20001], b[20001];

int main() {
  cin >> t;
  while(t--) {
    ret = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
      cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+m);
    int low = 0, high = m - 1, cnt = 0;
    while(low < n) {
      int tmp = m - 1;
      if(a[low] <= b[high]) {
        cnt++;
        high -= 1;
      }
      else {
        low += 1;
        high = tmp;
        ret += (m - cnt);
        cnt = 0;
      }
    }
    cout << ret << '\n';
  }
  return 0;
}