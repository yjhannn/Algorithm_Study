#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int k, a[1024];
vector<int> v, ans[11];

void solve(int first, int last, int level) {
  if(first > last) return;
  if(first == last) {
    ans[level].push_back(a[first]);
    return;
  }
  int mid = (first + last) / 2;
  ans[level].push_back(a[mid]);
  solve(first, mid - 1, level + 1);
  solve(mid + 1, last, level + 1);
  return;
}

int main() {
  cin >> k;
  int max = pow(2, k) - 1;
  for(int i = 0; i < max; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  solve(0, max, 1);
  for(int i = 1; i <= k; i++) {
    for(int j : ans[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}