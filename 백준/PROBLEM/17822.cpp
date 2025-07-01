#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, t, ret, a[51][51];

void hap() {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      ret += a[i][j];
    }
  }
}

void check() {
  bool erased = false;
  bool toErase[51][51] = {false};

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0) continue;
      int nj = (j % m) + 1;
      if (a[i][j] == a[i][nj]) {
        toErase[i][j] = toErase[i][nj] = true;
        erased = true;
      }
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0 || a[i + 1][j] == 0) continue;
      if (a[i][j] == a[i + 1][j]) {
        toErase[i][j] = toErase[i + 1][j] = true;
        erased = true;
      }
    }
  }

  // 실제 지우기
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (toErase[i][j]) a[i][j] = 0;
    }
  }
  if (!erased) {
    int sum = 0, cnt = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        if(a[i][j] != 0) {
          cnt++;
          sum += a[i][j];
        }
      }
    }
    if (cnt == 0) return;
    double avg = (double)sum / cnt;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        if(a[i][j] == 0) continue;
        if(a[i][j] > avg)
          a[i][j] -= 1;
        else if(a[i][j] < avg)
          a[i][j] += 1;
      }
    }
  }
}

void move(int index, int dir, int k) {
  int temp[51];
  for(int i = 1; i <= m; i++) {
    int j;
    if(dir == 0) {
      j = (i - 1 + k) % m + 1;
    }
    else if(dir == 1) {
      j = (i - 1 - k + m) % m + 1;
    }
    temp[j] = a[index][i];
  }
  for(int i = 1; i <= m; i++) {
    a[index][i] = temp[i];
  }
}

int main() {
  cin >> n >> m >> t;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  while(t--) {
    int x, d, k;
    cin >> x >> d >> k;
    for(int i = 1; i <= n; i++) {
      if(i % x == 0)
        move(i, d, k);
    }
    check();
  }
  
  hap();
  cout << ret;
  return 0;
}