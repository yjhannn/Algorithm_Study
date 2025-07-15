#include <iostream>
using namespace std;
int h, w, ret, board[501][501];

bool check(int x, int y) {
  bool lflag = false, rflag = false;
  for(int i = y + 1; i < w; i++) {
    if(board[x][i] == 1)
      rflag = true;
  }
  for(int i = y - 1; i >= 0; i--) {
    if(board[x][i] == 1)
      lflag = true;
  }
  if(rflag && lflag)
    return true;
  else
    return false;
}

int main() {
  cin >> h >> w;
  for(int i = 0; i < w; i++) {
    int val;
    cin >> val;
    for(int j = 0; j < val; j++) {
      board[j][i] = 1;
    }
  }
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(board[i][j] == 1)
        continue;
      if(check(i, j))
        ret++;
    }
  }
  cout << ret;
  return 0;
}