#include <iostream>
using namespace std;
int t, n, a[1000001];
int main() {
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n;
    int cnt;
    fill(a, a + n, 0);
    for(int j = 0; j < n; j++) {
      cin >> a[j];
    }
    int mx[1000001];
    mx[n - 1] = n - 1;
    for(int day = n - 2; day >= 0; day--) {
      if(a[day] > a[mx[day + 1]])
        mx[day] = day;
      else
        mx[day] = mx[day+1];
    }

    long long ans = 0;
    for(int day = 0; day < n; day++) {
      if(a[day] < a[mx[day]])
        ans += a[mx[day]] - a[day];
    }
    cout << ans << '\n';
  }

  return 0;
}