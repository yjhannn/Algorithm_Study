#include <iostream>
#include <stack>
using namespace std;
int n, ret;
stack<int> s;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if(k == 0) {
      s.pop();
    }
    else {
      s.push(k);
    }
  }

  while(s.size()) {
    ret += s.top();
    s.pop();
  }
  cout << ret;
  return 0;
}