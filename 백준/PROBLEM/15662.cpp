#include <iostream>
#include <cstring>
using namespace std;

int t, k, ret, a[1001][9];
string s;
void check() {
  for(int i = 0; i < t; i++) {
    if(a[i][0] == 1)
      ret++;
  }
}

void rotate(int num, int dir) {
  if(dir == 1) {
    int temp = a[num][7];
    for(int i = 7; i >= 1; i--) {
      a[num][i] = a[num][i - 1];
    }
    a[num][0] = temp;
  }
  else if(dir == -1) {
    int temp = a[num][0];
    for(int i = 0; i < 7; i++) {
      a[num][i] = a[num][i + 1];
    }
    a[num][7] = temp;
  }
}

int main() {
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> s;
    for(int j = 0; j < 8; j++) {
      a[i][j] = s[j] - '0';
    }
  }

  cin >> k;
  for(int i = 0; i < k; i++) {
    int num, dir;
    cin >> num >> dir;
    num-=1;

    int rotateDir[1001] = {0};
    rotateDir[num] = dir;

    // 왼쪽으로 회전 전파
    for(int j = num; j > 0; j--) {
      if(a[j][6] != a[j-1][2]) {
        rotateDir[j-1] = -rotateDir[j];
      } else {
        break;
      }
    }

    // 오른쪽으로 회전 전파
    for(int j = num; j < t - 1; j++) {
      if(a[j][2] != a[j+1][6]) {
        rotateDir[j+1] = -rotateDir[j];
      } else {
        break;
      }
    }

    // 회전 수행
    for(int j = 0; j < t; j++) {
      if(rotateDir[j] != 0)
        rotate(j, rotateDir[j]);
    }
  }
  check();
  
  cout << ret << '\n';
  return 0;
}