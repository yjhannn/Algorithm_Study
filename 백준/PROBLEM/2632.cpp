#include <iostream>
#include <map>
using namespace std;
int n, numA, numB, ret, a[1001], b[1001], sumA[2001], sumB[2001];
map<int, int> A, B;
void make(int n, int psum[], map<int, int>& mp) {
  for(int interval = 1; interval <= n; interval++) {
    for(int i = interval; i <= n + interval - 1; i++) {
      int sum = psum[i] - psum[i - interval];
      mp[sum]++;
      if(interval == n)
        break;
    }
  }
}

int main() {
  cin >> n;
  cin >> numA >> numB;
  for(int i = 1; i <= numA; i++) {
    cin >> a[i];
    sumA[i] = sumA[i - 1] + a[i];
  }
  for(int i = numA + 1; i <= 2*numA; i++) {
    sumA[i] = sumA[i - 1] + a[i - numA];
  }

  for(int i = 1; i <= numB; i++) {
    cin >> b[i];
    sumB[i] = sumB[i - 1] + b[i];
  }
  for(int i = numB + 1; i <= 2*numB; i++) {
    sumB[i] = sumB[i - 1] + b[i - numB];
  }
  make(numA, sumA, A);
  make(numB, sumB, B);
  ret += (A[n] + B[n]);
  for(int i = 1; i < n; i++) {
    ret += (A[i] * B[n - i]);
  }
  cout << ret;
  return 0;
}