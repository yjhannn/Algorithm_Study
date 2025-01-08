#include <iostream>

using namespace std;
int a[100001];
int psum[100001];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    psum[i] = psum[i-1] + a[i];
  }
  int i, j;
  for (int k = 0; k < m; k++) {
    cin >> i >> j;
    cout << psum[j] - psum[i-1] << '\n';
  }

  return 0;
}
