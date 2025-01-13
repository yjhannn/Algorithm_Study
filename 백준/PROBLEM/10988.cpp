#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;
  bool pel = 1;
  for(int i = 0; i < str.length(); i++) {
    if(str[i] != str[str.length() - 1 - i])
      pel = 0;
  }
  if(pel == 1)
    cout << 1;
  else
    cout << 0;
  return 0;
}