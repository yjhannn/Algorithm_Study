#include <iostream>
using namespace std;
typedef long long ll;
int cnt = 0;

int main() {
  ll a, b;
  cin >> a >> b;
  while(1) {
    cnt++;
    if(a == b) {
      cout << cnt;
      break;
    }
    else if(a > b) {
      cout << -1;
      break;
    }
    if(b%10 == 1){
      b -= 1;
      b/= 10;
    }
    else if(b % 2 == 0) {
      b /= 2;
    }
    else {
      cout << -1;
      break;
    }
  }
  return 0;
}