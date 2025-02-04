#include <iostream>
#include <string>
using namespace std;
string str;
int lcnt, vcnt; // lcnt는 모음, vcnt는 자음
bool isVowel(int idx) {
  return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main() {
  while(1) {
    cin >> str;
    if(str == "end")
      break;
    lcnt = 0, vcnt = 0;
    bool flag = 0;
    bool isInclude = 0;
    int prev = -1;
    for(int i = 0; i < str.length(); i++) {
      int idx = str[i];
      if(isVowel(idx)) {
        lcnt++;
        vcnt = 0, isInclude = 1;
      }
      else {
        vcnt++;
        lcnt = 0;
      }
      if(vcnt == 3 || lcnt == 3)
        flag = 1;
      if(i >= 1 && prev == idx && idx != 'e' && idx != 'o')
        flag = 1;
      prev = idx;
    }
    if(!isInclude)
      flag = 1;
    if(flag) {
      cout << "<" << str << "> " << "is not acceptable.\n";
    }
    else
      cout << "<" << str << "> " << "is acceptable.\n";
  }
  return 0;
}