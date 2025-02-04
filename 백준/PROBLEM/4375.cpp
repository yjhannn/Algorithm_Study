#include <iostream>

using namespace std;
typedef long long ll;
int n;
int main() {
  while(scanf("%d", &n) != EOF) {
    ll cnt = 1, ret = 1;
    while(1) {
      if (cnt % n == 0) {
        printf("%lld\n", ret);
        break;
      }
      else {
        cnt = (cnt*10) + 1;
        cnt %= n;
        ret++;
      }
    }
  }
  return 0;
}