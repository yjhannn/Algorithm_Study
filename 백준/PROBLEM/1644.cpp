#include <iostream>
using namespace std;
bool check[4000001];
int n, ret, low, high, sum, p, a[2000001];
int main() {
  cin >> n;
  // 소수 구하기
  for(int i = 2; i <= n; i++) {
    if(check[i])
      continue;
      for(int j = 2*i; j <= n; j+=i) {
        check[j] = 1;
      }
  }
  for(int i = 2; i <= n; i++) {
    if(!check[i])
      a[p++] = i;
  }

  // 연속 소수합 경우의 수 구하기
  while(1) {
    if(sum >= n)
      sum -= a[low++];
    else if(high == p)
      break;
    else
      sum += a[high++];
    if(sum == n)
      ret++;
  }
  cout << ret;
  return 0;
}