// 조합, 순열
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
pair<int, int> p;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int a[10];
  int sum = 0;
  for(int i = 0; i < 9; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < i; j++) {
      if(sum - a[i] - a[j] == 100) {
        p.first = i;
        p.second = j;
        break;
      }
    }
  }
  for(int i = 0; i < 9; i++) { 
    if(i == p.first || i == p.second)
      continue;
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  for(int i : v) cout << i << "\n";

  return 0;
}