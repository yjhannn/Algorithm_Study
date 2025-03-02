// 짝짓기 문제 -> 스택!
// 오큰수가 나오지 않으면 일단 스택에 담아놓다가 큰 수가 나오면 그것이 바로 오큰수
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
stack<int> s;
int a[1000001], result[1000001], n;

int main() {
  cin >> n;
  memset(result, -1, sizeof(result));
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    while(s.size() && a[s.top()] < a[i]) {
      result[s.top()] = a[i];
      s.pop();
    }
    s.push(i);
  }
  for(int i = 0; i < n; i++) {
    cout << result[i] << " ";
  }
  return 0;
}