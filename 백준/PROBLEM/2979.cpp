#include <iostream>
using namespace std;

int main() {
  int time[101] = {0,};
  int a, b, c;
  cin >> a >> b >> c;
  int n, m;
  int max = 0;
  for(int i = 0; i < 3; i++) {
    cin >> n >> m;
    for(int j = n; j < m; j++)
      time[j]++;
    if(max < m)
      max = m;
  }
  int sum = 0;
  for (int i = 1; i <= max; i++) {
    if(time[i] == 1)
      sum += a;
    else if(time[i] == 2)
      sum += b*2;
    else if(time[i] == 3) 
      sum += c*3;
  }
  cout << sum;
  return 0;
}