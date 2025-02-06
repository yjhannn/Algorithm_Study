#include <iostream>
#include <string>
using namespace std;
int lp, rp;
int n;
string str;
string check(string str) {
  lp = 0; rp = 0;
  for(int i = 0; i < str.size(); i++) {
    if(str[i] == '(')
      lp += 1;
    else if(str[i] == ')')
      rp += 1;
    if(rp > lp)
      return "NO";
  }
  if(lp == rp)
    return "YES";
  else
    return "NO";
}
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> str;
    cout << check(str) << '\n';
  }

  return 0;
}