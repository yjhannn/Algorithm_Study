#include <iostream>
using namespace std;
int pos_x, pos_y, mx = -1;

int main() {
  int num;
  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) {
      cin >> num;
      if(mx < num) {
        mx = num;
        pos_x = i; pos_y = j;
      }
    }
  }
  cout << mx << '\n' << pos_x << " " << pos_y;
  return 0;
}