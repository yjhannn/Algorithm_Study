#include <iostream>
#include <stack>
#include <utility>
using namespace std;
int n, val;
stack<pair<int, int> > s;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> val;
    
    if(s.empty()) {
      s.push(make_pair(i, val));
      cout << 0 << " ";
    }
    else {
      while(!s.empty()) {
        if(s.top().second > val) {
          cout << s.top().first << " ";
          break;
        }
        else {
          s.pop();
        }
      }
      if(s.empty())
        cout << 0 << " ";
      s.push(make_pair(i, val));
    }
  }
  
  return 0;
}