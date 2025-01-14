// 조합
#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n;
  cin >> m;
  int suit[n+1];
  for(int i = 0; i < n; i++) {
    cin >> suit[i];
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      if(suit[i] + suit[j] == m)
        ans++;
    }
  }

  cout << ans;
  return 0;
}