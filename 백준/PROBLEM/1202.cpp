#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, k, m, v, ret;
long long int c;
vector<pair<int, int> > jw;
vector<int> bag;
priority_queue<int> pq;
int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> m >> v;
    jw.push_back(make_pair(m, v));
  }
  for(int i = 0; i < k; i++) {
    cin >> c;
    bag.push_back(c);;
  }
  sort(jw.begin(), jw.end());
  sort(bag.begin(), bag.end());

  int j = 0;
  for(int i = 0; i < k; i++) {
    while(j < n && jw[j].first <= bag[i]) {
      pq.push(jw[j].second);
      j++;
    }
    if(!pq.empty()){
      ret += pq.top();
      pq.pop();
    }
  }
  cout << ret;

  return 0;
}