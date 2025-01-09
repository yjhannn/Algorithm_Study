#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  int count[27] = {0, };
  cin >> str;
  count[str[0] - 'a'] = 1;
  for(int i = 1; i < str.size(); i++) {
    count[str[i] - 'a']++;
  }
  for(int i = 0; i < 26; i++) {
    cout << count[i] << " ";
  }

  return 0;
}