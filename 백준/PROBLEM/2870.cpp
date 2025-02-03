#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
string str, ret;
vector<string> v;
void solve() {
  while(1) {
    if(ret[0] == '0' && ret.size())
      ret.erase(ret.begin());
    else
      break;
  }
  if(!ret.size())
    ret = "0";
  v.push_back(ret);
  ret = "";
}
bool compare(string a, string b) {
  if(a.size() == b.size())
    return a < b;
  return a.size() < b.size();
}
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> str;
    ret = "";
    for(int j = 0; j < str.length(); j++) {
      if(isdigit(str[j])) {
        ret += str[j];
      }
      else if(ret.size())
        solve();
    }
    if(ret.size())
      solve();
  }
  sort(v.begin(), v.end(), compare);
  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << '\n';
  }
  return 0;
}