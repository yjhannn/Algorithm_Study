#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[201][201], psum[201][201];
int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> a[i][j];
      psum[i][j] = a[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
    }
  }
  int ret = -987654321;

  for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < i; k++)
			{
				for (int m = 0; m < j; m++)
				{
					ret = max(ret, psum[i][j] - psum[k][j] - psum[i][m] + psum[k][m]);
				}
			}
		}
	}
  cout << ret;
  
  return 0;
}