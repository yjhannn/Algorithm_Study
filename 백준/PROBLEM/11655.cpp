#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  getline(cin, str);
  for(int i = 0; i < str.length(); i++) {
    if(str[i] >= 65 && str[i] < 97) {
      if(str[i] + 13 > 90)
        str[i] = str[i] + 13 - 26;
      else  
        str[i] = str[i] + 13;
    }
    else if(str[i] >= 97 && str[i] <= 122)
      if(str[i] + 13 > 122)
        str[i] = str[i] + 13 - 26;
      else
        str[i] = str[i] + 13;
  }
  cout << str;
  return 0;
}