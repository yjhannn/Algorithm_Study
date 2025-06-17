// Optimal Page Replacement
#include <iostream>
#include <vector>
#include <algorithm> // find 함수
using namespace std;
const int INF = 987654321;
int n, k, a[101], visited[101], ret;
vector<int> v;
int main() {
  cin >> n >> k;
  for(int i = 0; i < k; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < k; i++) {
    if(!visited[a[i]]) {
      if(v.size() == n) {
        int lst = 0, cur;
        for(int num : v) {
          int here = INF;
          for(int j = i + 1; j < k; j++) {
            if(num == a[j]) {
              here = j;
              break;
            }
          }
          if(lst < here) {
            lst = here;
            cur = num;
          }
        }
        visited[cur] = 0;
        ret++;
        v.erase(find(v.begin(), v.end(), cur));
      }
      v.push_back(a[i]);
      visited[a[i]] = 1;
    }
  }
  cout << ret;
  return 0;
}