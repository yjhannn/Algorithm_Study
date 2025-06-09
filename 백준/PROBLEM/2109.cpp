#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
int n, p, d, ret, visited[10001];
priority_queue<int, vector<int>, greater<int> > pq;
vector<pair<int, int> > v;
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> p >> d;
    v.push_back(make_pair(d, p));
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++) {
    pq.push(v[i].second);
    if(pq.size() > v[i].first) 
      pq.pop();
  }

  while(!pq.empty()) {
    ret += pq.top();
    pq.pop();
  }
  cout << ret;
  return 0;
}