#include <iostream>
#include <string>

using namespace std;
string str;
bool flag = 1;
int main() {
  cin >> str;
  int i = 0;
  while(i < str.size()) {
    if(str.substr(i, 2) == "pi") {
      i += 2;
    }
    else if(str.substr(i, 2) == "ka") {
      i += 2;
    }
    else if(str.substr(i, 3) == "chu") {
      i += 3;
    }
    else {
      flag = 0;
      break;
    }
  }

  if(flag == 1) {
    cout << "YES";
  }
  else {
    cout << "NO";
  }
  return 0;
}