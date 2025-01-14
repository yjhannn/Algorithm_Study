#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  string str;
  int count = 0;
  for(int i = 0; i < n; i++) {
    cin >> str;
    stack<char> stack;
    for(char a : str) {
      if(stack.size() && stack.top() == a) // top을 체크할 때 항상 size를 체크하고 들어갈 것
        stack.pop();
      else
        stack.push(a);
    }
    if(stack.size() == 0)
      count++;
    
  }
  cout << count;
  return 0;
}