#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> v;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end());
  
  for(int i = 0; i < n; i++) {
    cout << v[i] << '\n';
  }
  return 0;
}