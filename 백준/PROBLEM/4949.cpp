//짝짓기 -> 스택을 사용하는 것을 먼저 고려할 것!
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
  while(1) {
    string str;
    stack<int> stk;
    bool check = true;
    getline(cin, str);
    if(str == ".")
      break;
    for(int i = 0; i < str.size(); i++) {
      if(str[i] == ')') {
        if(stk.size() == 0 || stk.top() == '[') {
          check = false;
          break;
        }
        else
          stk.pop();
      }
      else if(str[i] == ']') {
        if(stk.size() == 0 || stk.top() == '(') {
          check = false;
          break;
        }
        else
          stk.pop();
      }
      if(str[i] == '(')
        stk.push(str[i]);
      else if(str[i] == '[')
        stk.push(str[i]);
    }
    if(check && stk.size() == 0)
      cout << "yes\n";
    else
      cout << "no\n";
  }

  return 0;
}