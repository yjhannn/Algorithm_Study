#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int n, m;
vector<string> word;
map<string, int> mp;
string str;

bool compare(string a, string b) {
  if(a.size() == b.size() && mp[a] == mp[b]) 
    return a < b;
  else if (mp[a] == mp[b])
    return a.size() > b.size();
  return mp[a] > mp[b];
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> str;
    if(str.size() < m)
      continue;
    if(mp.find(str) == mp.end()) {
      mp[str] = 0;
      word.push_back(str);
    }
    mp[str]++;
  }
  sort(word.begin(), word.end(), compare);
  for(int i = 0; i < word.size(); i++) {
    cout << word[i] << '\n';
  }

  return 0;
}