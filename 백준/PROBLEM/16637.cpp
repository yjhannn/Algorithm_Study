// 누적합을 이용한다!
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, mx = -987654321;
string str;
vector<int> num;
vector<char> op;

int calculate(int a, int b, char op) {
  int ret = a;
  if(op == '+')
    ret += b;
  else if(op == '-')
    ret -= b;
  else if(op == '*')
    ret *= b;
  return ret;
}

void solve(int idx, int val) {
  if(idx == num.size() - 1) {
    mx = max(mx, val);
    return;
  }
  solve(idx+1, calculate(val, num[idx+1], op[idx]));
  if(idx + 2 <= num.size() - 1) {
    int temp = calculate(num[idx+1], num[idx+2], op[idx+1]);
    solve(idx+2, calculate(val, temp, op[idx]));
  }
  return;
}

int main() {
  cin >> n >> str;
  for(int i = 0; i < n; i++) {
    if(isdigit(str[i])) {
      num.push_back(str[i] - '0');
    }
    else
      op.push_back(str[i]);
  }
  solve(0, num[0]);
  cout << mx;
  return 0;
}