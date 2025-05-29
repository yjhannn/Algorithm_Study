#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  int sum = 0;
  string ans;
  while(str1.length() || str2.length() || sum) {
    if(str1.length()) {
      sum += str1.back() - '0';
      str1.pop_back();
    }
    if(str2.length()) {
      sum += str2.back() - '0';
      str2.pop_back();
    }
    ans += (sum % 10) + '0';
    sum /= 10;
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}