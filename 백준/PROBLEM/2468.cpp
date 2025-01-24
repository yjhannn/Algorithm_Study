// 맞왜틀 Tip
// 반례를 생각할것
// 반례 : 최소 최대, 없거나 있거나
// 이 문제에서는 아무지역도 침수되지 않았을 때를 잘 생각해야 함
// ret = 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int visited[101][101];
int a[101][101];
int n, ret = 1, num, ans;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void dfs(int y, int x, int height) {
  visited[y][x] = 1;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
    if(a[ny][nx] > height && !visited[ny][nx]) {
      dfs(ny, nx, height);
    }
  }
  return;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> num;
      a[i][j] = num;
    }
  }
  for(int i = 1; i <= 100; i++) {
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
    ans = 0;
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        if(a[j][k] > i && !visited[j][k]) {
          dfs(j, k, i);
          ans++;
        }
      }
    }
    ret = max(ret, ans);
  }
  cout << ret << '\n';
  
  return 0;
}