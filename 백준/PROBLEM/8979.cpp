#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;

struct Country{
  int no, gold, silver, bronze;
};

bool compare(Country a, Country b) {
  if(a.gold != b.gold)
    return a.gold > b.gold;
  if(a.silver != b.silver)
    return a.silver > b.silver;
  return a.bronze > b.bronze;
}

int main() {
  cin >> n >> k;
  vector<Country> countries(n);
  for(int i = 0; i < n; i++) {
    cin >> countries[i].no >> countries[i].gold >> countries[i].silver >> countries[i].bronze;    
  }
  sort(countries.begin(), countries.end(), compare);
  int rank = 1;
  for (int i = 0; i < n; ++i) {
    if (countries[i].no == k) {
      for (int j = 0; j < i; ++j) {
        if (countries[j].gold == countries[i].gold &&
          countries[j].silver == countries[i].silver &&
          countries[j].bronze == countries[i].bronze) {
          rank = j + 1;
          break;
        }
      }
      cout << rank << '\n';
      break;
    }
    rank++;
  }

  return 0;
}