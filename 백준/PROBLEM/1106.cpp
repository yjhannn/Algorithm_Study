#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int c, n, sum, ret = 987654321;
int dp[100001];
vector<pair<int, int> > v;
int main() {
  cin >> c >> n;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  for(int i = 1; i <= 100000; i++) {
    for(int j = 0; j < n; j++) {
      if(i % v[j].first == 0) 
        dp[i] = max(dp[i], (i / v[j].first) * v[j].second);
      if(i - v[j].first >= 0)
        dp[i] = max(dp[i], dp[i-v[j].first] + v[j].second);
    }
    if(dp[i] >= c) {
      cout << i;
      return 0;
    }
  }
  return 0;
}