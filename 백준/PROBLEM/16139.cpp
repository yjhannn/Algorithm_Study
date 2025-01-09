#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string str;
  int n;
  char c;
  int l, r;
  int count[27][200001];
  cin >> str;
  cin >> n;
  count[str[0] - 'a'][0] = 1;
  for(int i = 1; i < str.size(); i++) {
    for(int j = 0; j < 27; j++) {
      count[j][i] = count[j][i-1];
    }
    count[str[i]-'a'][i]++;
  }
  for(int i = 0; i < n; i++) {
    cin >> c >> l >> r;
    if(l == 0)
      cout << count[c - 'a'][r] << '\n';
    else
      cout << count[c - 'a'][r] - count[c - 'a'][l-1] << '\n';
  }
  return 0;
}
