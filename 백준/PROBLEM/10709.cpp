#include <iostream>

using namespace std;
char weather[101][101];
int ans[101][101] = {101, };
int h, w;

int main() {
  cin >> h >> w;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> weather[i][j];
      if(weather[i][j] == 'c') {
        ans[i][j] = 0;
      }
      else
        ans[i][j] = -1;
    }
  }
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(ans[i][j] == 0) {
        int val = 1;
        while(ans[i][j+1] == -1) {
          ans[i][j+1] = val++;
          j++;
        }
      }
    }
  }
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}