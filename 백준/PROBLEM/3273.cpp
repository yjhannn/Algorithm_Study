#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100001], sum, st, en, ret;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> sum;
  sort(a, a+n);
  st = 0, en = n-1;
  while(st != en) {
    if(a[st] + a[en] == sum) {
      ret++;
    }
    if(a[st] + a[en] >= sum)
      en--;
    else if(a[st] + a[en] < sum)
      st++;
    
  }
  cout << ret;
  return 0;
}