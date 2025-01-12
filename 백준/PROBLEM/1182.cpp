#include <iostream>
using namespace std;

int n, s, sum, ans;
int arr[21];

void dfs(int i, int sum) {
  if(i == n)
    return;
  if(sum + arr[i] == s)
    ans++;
  dfs(i + 1, sum);
  dfs(i + 1, sum + arr[i]);

}

int main() {
  cin >> n >> s;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  ans = 0;
  dfs(0,0);
  cout << ans;

  return 0;
}