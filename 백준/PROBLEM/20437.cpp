#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int t, k, low_ans, max_ans;
vector<int> v[26];
void solve() {
  low_ans = 1e9, max_ans = -1;
  for(int i = 0; i < 26; i++) {
    if(v[i].size() < k)
      continue;
    
    // 이 부분의 아이디어가 생각 안났음 
    for(int j = 0; j <= v[i].size() - k; j++) {
      int ret = v[i][j+k-1] - v[i][j] + 1;
      low_ans = min(low_ans, ret);
      max_ans = max(max_ans, ret);
    }
  }
}

int main() {
  cin >> t;
  while(t--) {
    // vector clean
    for(int i = 0; i < 26; i++)
      v[i].clear();
    string str;
    cin >> str >> k;
    for(int i = 0; i < str.size(); i++) {
      v[str[i] - 'a'].push_back(i);
    }
    solve();
    if(max_ans == -1) {
      cout << -1 << '\n';
    }
    else
      cout << low_ans << " " << max_ans << '\n';
  }
  return 0;
}