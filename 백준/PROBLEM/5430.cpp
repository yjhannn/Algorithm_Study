
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
using namespace std;



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, t;

  cin >> t;
  while(t--) {
    string order, num;
    string number = ""; // 숫자만 담는 string
    bool reverse = false, error = false;
    deque<int> dq;
    cin >> order;
    cin >> n;
    cin >> num;
    for(int i = 0; i < num.length(); i++) {
      if(isdigit(num[i])) 
        number += num[i];
      else {
        if(!number.empty()) {
          dq.push_back(stoi(number));
          number = "";
        }
      }
    }

    for(auto o : order) {
      if (o == 'R') {
        if (reverse) // reverse == true
          reverse = false;
        else
          reverse = true;
      }
      else {
        if (dq.empty()) {
          cout << "error" << '\n';
          error = true;
          break;
        }
        if (reverse)
          dq.pop_back();
        else
          dq.pop_front();
      }
    }

    if(!error)
      cout << '[';
    if(reverse && !dq.empty()) {
      for (auto o = dq.rbegin(); o != dq.rend(); o++) {
        if(o == dq.rend() - 1)
          cout << *o;
        else
          cout << *o << ',';
      }
    }
    else if(!reverse && !dq.empty()) {
      for (auto o = dq.begin(); o != dq.end(); o++) {
        if(o == dq.end() - 1) 
          cout << *o;
        else
          cout << *o << ',';
      }
    }
    if(!error)
      cout << "]\n";
  }

  return 0;
}

