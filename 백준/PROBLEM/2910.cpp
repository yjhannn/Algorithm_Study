#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n, c, msg;
vector<pair<int, int>> v;
map<int, int> m, m_first;
bool compare(pair<int, int > a, pair<int, int > b) {
  if(a.first == b.first) {
    return m_first[a.second] < m_first[b.second];
  }
  return a.first > b.first;
}
int main() {
  cin >> n >> c;
  for(int i = 0; i < n; i++) {
    cin >> msg;
    m[msg]++;
    if(m_first[msg] == 0)
      m_first[msg] = i + 1;
  }
  for(auto it : m) {
    v.push_back({it.second, it.first});
  }
  sort(v.begin(), v.end(), compare);
  for(auto it : v) {
    for(int j = 0; j < it.first; j++)
      cout << it.second << " ";
  }
  return 0;
}