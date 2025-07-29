#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 987654321;
int n, dp[16][1 << 16], dist[16][16];

int solve(int here, int visited) {
  if(visited == (1 << n) - 1) {
    if(dist[here][0])
      return dist[here][0];
    else
      return INF;
  }
  int &ret = dp[here][visited];
  if(ret != -1)
    return ret;
  ret = INF;
  for(int i = 0; i < n; i++) {
    if(dist[here][i] == 0)
      continue;
    if(visited & (1 << i))
      continue;
    ret = min(ret, solve(i, visited | (1 << i)) + dist[here][i]);
  }
  return ret;
}

int main() {
  cin >> n; 
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> dist[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 1);
  return 0;
}