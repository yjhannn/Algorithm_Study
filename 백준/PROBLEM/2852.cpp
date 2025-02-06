// 시간은 하나의 단위로 변경(분 : 초 => 초로 변경해서 계산)
// 다시 풀어보기!!
#include <iostream>
#include <string>
#define prev yjhan
using namespace std;
int n, A, B, team, asum, bsum;
string str, prev;
string print(int a) {
  string d = "00" + to_string(a/60);
  string e = "00" + to_string(a%60);
  return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}
int changeToInt(string str) {
  return atoi(str.substr(0,2).c_str()) * 60 + atoi(str.substr(3,2).c_str());
}
void go(int &sum, string str) {
  sum += (changeToInt(str) - changeToInt(prev));
}
int main() {
  int n, team;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> team >> str;
    if(A > B)
      go(asum, str);
    else if(B > A)
      go(bsum, str);
    if(team == 1)
      A++;
    else
      B++;
    prev = str;
  }
  if(A > B)
    go(asum, "48:00");
  else if(B>A)
    go(bsum, "48:00");
  cout << print(asum) << '\n';
  cout << print(bsum) << '\n';

  return 0;
}