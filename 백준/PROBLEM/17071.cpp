#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k, turn = 1, ok, visited[2][500001];


int main() {
  cin >> n >> k;
  if(n == k) {
    cout << 0;
    return 0;
  }
  queue<int> q;
  visited[0][n] = 1;
  q.push(n);
  while(q.size()) {
    k += turn;
    if(k > 500000)
      break;
    if(visited[turn % 2][k]) {
      ok = 1;
      break;
    }
    int qSize = q.size();
    for(int i = 0; i < qSize; i++) {
      int here = q.front();
      q.pop();
      for(int next : {here + 1, here - 1, here * 2}) {
        if(next < 0 || next > 500000 || visited[turn % 2][next])
          continue;
        visited[turn % 2][next] = visited[(turn + 1) % 2][here] + 1;
        if(next == k) {
          ok = 1;
          break;
        }
        q.push(next);
      }
      if(ok)
        break;
    }
    if(ok)
      break;
    turn++;
  }
  if(ok)
    cout << turn;
  else
    cout << -1;
  return 0;
}