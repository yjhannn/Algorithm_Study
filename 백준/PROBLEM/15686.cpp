#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n, m, ret, a[51][51], result = 999999999;
vector<vector<int> >chickenList;
vector<pair<int, int> > myhome, chicken;
// 조합 찾기
void combi(int start, vector<int> v) {
  if(v.size() == m) {
    chickenList.push_back(v);
    return;
  }
  for(int i = start + 1; i < chicken.size(); i++) {
    v.push_back(i);
    combi(i, v);
    v.pop_back();
  }
  return;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> a[i][j];
      if(a[i][j] == 1)
        myhome.push_back(make_pair(i, j));
      if(a[i][j] == 2)
        chicken.push_back(make_pair(i, j));
    }
  }
  vector<int> v;
  combi(-1, v);
  for(vector<int> chList : chickenList) {
    int ans = 0;
    for(pair<int, int> home : myhome) {
      int min_val = 999999999;
      for(int ch : chList) {
        int distance = abs(home.first - chicken[ch].first) +
        abs(home.second - chicken[ch].second);
        min_val = min(min_val, distance);
      }
      ans += min_val;
    }
    result = min(result, ans);
  }
  cout << result;
  return 0;
}