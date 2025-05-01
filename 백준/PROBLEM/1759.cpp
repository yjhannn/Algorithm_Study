#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, C;

void solve(vector<char> a, int here, string str, int n, int m) { // n : 자음 수, m : 모음 수
  str.push_back(a[here]);
  if(a[here] == 'a' || a[here] == 'e' || a[here] == 'i' || a[here] == 'o' || a[here] == 'u') {
    m++;
  }
  n = L-m;
  if(str.length() == L) {
    if(m >= 1 && n >= 2) {
      cout << str << '\n';
    }
    return;
  }
  for(int i = here + 1; i < C; i++) {
    solve(a, i, str, n, m);
  }
  return;
}

int main() {
  cin >> L >> C;
  vector<char> a(C);
  for(int i = 0; i < C; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for(int i = 0; i <= C - L; i++) {
    solve(a, i, "", 0, 0);
  }
  return 0;
}