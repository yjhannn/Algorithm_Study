#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string str, bomb, extra = "";
  cin >> str;
  cin >> bomb;
  int s_length = str.length();
  int b_length = bomb.length();
  for(int i = 0; i < str.length(); i++) {
    extra += str[i];
    if(extra.size() >= b_length) {
      bool check = true;
      for(int j = 0; j < b_length; j++) {
        if(extra[extra.length() - b_length + j] != bomb[j]) {
          check = false;
          break;
        }
      }
      if(check) {
        extra.erase(extra.length() - b_length, b_length);
      }
    }
  }
  // while(1) {
  //   if(str.find(bomb) == -1)
  //     break;
  //   int index = str.find(bomb);
  //   str.erase(index, bomb.size());
  // }
  if(extra.length() == 0)
    cout << "FRULA" << '\n';
  else
    cout << extra << '\n';

  return 0;
}