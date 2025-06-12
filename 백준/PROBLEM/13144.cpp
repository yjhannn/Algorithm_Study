#include <iostream>
using namespace std;
long long n, high, low, ret, a[100001], cnt[100001];

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  while(high < n) {
    if(!cnt[a[high]]) {
      cnt[a[high]]++;
      high++;
    }
    else {
      ret += (high - low);
      cnt[a[low]]--;
      low++;
    }
  }
  ret += (long long)(high - low) * (high - low + 1) / 2;
  cout << ret;
  return 0;
}