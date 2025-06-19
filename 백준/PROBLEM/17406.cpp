#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k, a[51][51], original[51][51];
int ret = 987654321;

struct OP { int r, c, s; } op[6];
int idx[6];

void check_ret() {
  for(int i = 1; i <= n; i++) {
    int sum = 0;
    for(int j = 1; j <= m; j++) {
      sum += a[i][j];
    }
    ret = min(ret, sum);
  }
}

void rotate(int startx, int starty, int endx, int endy) {
  if(startx >= endx || starty >= endy) return;
  int prev = a[startx][starty];
  for(int i = starty + 1; i <= endy; i++) {
    int temp = a[startx][i];
    a[startx][i] = prev;
    prev = temp;
  }
  for(int i = startx + 1; i <= endx; i++) {
    int temp = a[i][endy];
    a[i][endy] = prev;
    prev = temp;
  }
  for(int i = endy - 1; i >= starty; i--) {
    int temp = a[endx][i];
    a[endx][i] = prev;
    prev = temp;
  }
  for(int i = endx - 1; i >= startx; i--) {
    int temp = a[i][starty];
    a[i][starty] = prev;
    prev = temp;
  }
  rotate(startx+1, starty+1, endx-1, endy-1);
}

int main() {
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> a[i][j];
      original[i][j] = a[i][j];
    }
  }
  for(int i = 0; i < k; i++) {
    cin >> op[i].r >> op[i].c >> op[i].s;
    idx[i] = i;
  }

  do {
    memcpy(a, original, sizeof(a));
    for(int i = 0; i < k; i++) {
      int r = op[idx[i]].r;
      int c = op[idx[i]].c;
      int s = op[idx[i]].s;
      rotate(r - s, c - s, r + s, c + s);
    }
    check_ret();
  } while(next_permutation(idx, idx + k));

  cout << ret;
  return 0;
}