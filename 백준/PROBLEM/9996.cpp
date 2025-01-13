#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string str, prefix, suffix;
  string input;
  cin >> n;
  cin >> str;
  int index = str.find('*');
  prefix = str.substr(0, index);
  suffix = str.substr(index + 1);
  for(int i = 0; i < n; i++) {
    cin >> input;
    if(prefix.size() + suffix.size() > input.size()) {
      cout << "NE\n";
    }
    else {
      if(prefix == input.substr(0, prefix.size()) 
      && suffix == input.substr(input.size() - suffix.size()))
        cout << "DA\n";
      else
        cout << "NE\n";
    }
  }

  return 0;
}