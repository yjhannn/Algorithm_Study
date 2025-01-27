#include <iostream>

using namespace std;
int N, M, J, lpos, rpos, apple, cnt;
int main() {
  cin >> N >> M;
  cin >> J;
  lpos = 1;
  for(int i = 0; i < J; i++) {
    rpos = lpos + M - 1;
    cin >> apple;
    if(apple >= lpos && rpos >= apple) continue;
    else {
      if(apple < lpos) {
        cnt += (lpos - apple);
        lpos = apple;
      }
      else {
        cnt += (apple - rpos);
        lpos += (apple - rpos);
      }
    }
  }
  cout << cnt;
  return 0;
}