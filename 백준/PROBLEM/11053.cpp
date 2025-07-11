#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ret;
vector<int> v, lis;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
    if(lis.empty() || lis.back() < num) {
      lis.push_back(num);
    }
    else {
      auto lowerPos = lower_bound(lis.begin(), lis.end(), num);
      *lowerPos = num;
    }
  }
  ret = lis.size();
  cout << ret;
  return 0;
}