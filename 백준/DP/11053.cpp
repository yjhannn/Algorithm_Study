// DP
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  int A[1001];
  int DP[1001] = {1, };
  
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= n; i++) {
    DP[i] = 1;
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j < i; j++) {
      if(A[i] > A[j]) {
        DP[i] = max(DP[i], DP[j] + 1);
      }
    }
  }

  sort(DP, DP+n+1);
  cout << DP[n];

  return 0;
}