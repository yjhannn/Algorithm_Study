#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, ans, alphabet[27];
vector<string> v;

void dfs(int now, int cnt) {
  if(cnt == 0) {
    int ret = 0;
    for(string s : v) {
      bool isTrue = true;
      for(char c : s) {
        if(alphabet[c - 'a'] == 0) {
          isTrue = false;
          break;
        }
      }
      if(isTrue)
        ret++;
    }
    ans = max(ret, ans);
    return;
  }

  for(int i = now; i < 26; i++) {
    if(alphabet[i])
      continue;
    alphabet[i] = 1;
    dfs(i, cnt - 1);
    alphabet[i] = 0;
  }
}
int main() {  
  cin >> n >> k;
  // a, c, i, n, t 필수 값
  alphabet[0] = alphabet[2] = alphabet[8] = alphabet[13] = alphabet[19] = 1;

  string str;
  for(int i = 0; i < n; i++) {
    cin >> str;
    v.push_back(str);
  }
  if(k < 5) {
    cout << 0;
    exit(0);
  }
  dfs(0, k - 5);
  cout << ans << '\n';

  return 0;
}