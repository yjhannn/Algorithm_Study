#include <iostream>
using namespace std;
int n, t, a[101][101];

int main() {
  t = 0;
  while(1) {
    int sum = 0;
    int mx = -987654321;
    cin >> n;
    if(n == 0) break;
    ++t;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    
    // ㅡ
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n - 3; j++) {
        sum = 0;
        sum = a[i][j] + a[i][j+1] + a[i][j+2] + a[i][j+3];
        if(sum > mx)
          mx = sum;
      }
    }

    // ㅣ
    for(int i = 0; i < n - 3; i++) {
      for(int j = 0; j < n; j++) {
        sum = 0;
        sum = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+3][j];
        if(sum > mx) {
          mx = sum;
        }
      }
    }

    // ㅓ
    for(int i = 0; i < n - 2; i++) {
      for(int j = 0; j < n - 1; j++) {
        sum = 0;
        sum = a[i+1][j] + a[i+1][j+1] + a[i][j+1] + a[i+2][j+1];
        if(sum > mx)
          mx = sum;
      }
    }

    // ㅗ
    for(int i = 0; i < n - 1; i++) {
      for(int j = 0; j < n - 2; j++) {
        sum = 0;
        sum = a[i+1][j] + a[i+1][j+1] + a[i][j+1] + a[i+1][j+2];
        if(sum > mx)
          mx = sum;
      }
    }

    // ㅏ
    for(int i = 0; i < n - 2; i++) {
      for(int j = 0; j < n - 1; j++) {
        sum = 0;
        sum = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+2][j];
        if(sum > mx)
          mx = sum;
      }
    }

    // ㅜ
    for(int i = 0; i < n - 1; i++) {
      for(int j = 0; j < n - 2; j++) {
        sum = 0;
        sum = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i][j+2];
        if(sum > mx)
          mx = sum;
      }
    }

    // 네모
    for(int i = 0; i < n - 1; i++) {
      for(int j = 0; j < n - 1; j++) {
        sum = 0;
        sum = a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1];
        if(sum > mx)
          mx = sum;
      }
    }

    // --
    //  --
    for(int i = 0; i < n - 1; i++) {
      for(int j = 0; j < n - 2; j++) {
        sum = 0;
        sum = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+1][j+2];
        if(sum > mx)
          mx = sum;
      }
    }

    //   ㅣ
    // ㅣ ㅣ
    // ㅣ
    for(int i = 0; i < n - 2; i++) {
      for(int j = 0; j < n - 1; j++) {
        sum = 0; 
        sum = a[i][j+1] + a[i+1][j] + a[i+1][j+1] + a[i+2][j];
        if(sum > mx)
          mx = sum;
      }
    }

    // ---
    //   -
    for(int i = 0; i < n - 1; i++) {
      for(int j = 0; j < n - 2; j++) {
        sum = 0; 
        sum = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+2];
        if(sum > mx)
          mx = sum;
      }
    }

    // ㅣ
    // ㅣ
    //ㅣㅣ
    for(int i = 0; i < n - 2; i++) {
      for(int j = 0; j < n - 1; j++) {
        sum = 0;
        sum = a[i][j+1] + a[i+1][j+1] + a[i+2][j] + a[i+2][j+1];
        if(sum > mx)
          mx = sum;
      }
    }

    // -
    // ---
    for(int i = 0; i < n - 1; i++) {
      for(int j = 0; j < n - 2; j++) {
        sum = 0;
        sum = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+1][j+2];
        if(sum > mx)
          mx = sum;
      }
    }

    // ㅣ ㅣ
    // ㅣ
    // ㅣ
    for(int i = 0; i < n - 2; i++) {
      for(int j = 0; j < n - 1; j++) {
        sum = 0;
        sum = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+2][j];
        if(sum > mx)
          mx = sum;
      }
    }


    cout << t <<". " << mx << '\n';
  }
  return 0;
}