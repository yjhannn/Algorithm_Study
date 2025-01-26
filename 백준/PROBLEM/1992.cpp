#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
char a[101][101];
string str;
string solve(int y, int x, int size) {
  if(size == 1) {
    return string(1, a[y][x]);
  }
  string ret = "";
  char val = a[y][x];
  for(int i = y; i < y + size; i++) {
    for(int j = x; j < x + size; j++) {
      if(val != a[i][j]) {
        ret += '(';
        ret += solve(y,x, size/2);
        ret += solve(y, x + size/2, size/2);
        ret += solve(y + size/2, x, size/2);
        ret += solve(y + size/2, x + size/2, size/2);
        ret += ')';
        return ret;
      }
    }
  }
  return string(1, a[y][x]);
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> str;
    for(int j = 0; j < n; j++) {
      a[i][j] = str[j];
    }
  }
  cout << solve(0, 0, n);
  return 0;
}