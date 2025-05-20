#include <iostream>
#include <cmath>
using namespace std;
int N, L, ans = 0, map[101][101], map2[101][101];

void garo(int now, int a[101][101]) {
  int cnt = 1, i;
  for(i = 0; i < N-1; i++) {
    if(a[now][i] == a[now][i+1])
      cnt++;
    else if(a[now][i] - a[now][i+1] == -1 && cnt >= L)
      cnt = 1;
    else if(a[now][i] - a[now][i+1] == 1 && cnt >= 0)
      cnt = -L + 1;
    else
      break;
  }
  if(i == N - 1 && cnt >= 0)
    ans++;
  return;
}

int main() {
  cin >> N >> L;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> map[i][j];
      map2[j][i] = map[i][j];
    }
  }
  for(int i = 0; i < N; i++) {
    garo(i, map);
    garo(i, map2);
  }

  cout << ans;

  return 0;
}