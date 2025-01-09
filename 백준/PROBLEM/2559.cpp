#include <iostream>
using namespace std;
int N, K; 
int psum[100001];
int ret = -10000001;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++){
		int input;
		cin >> input;
		psum[i] = psum[i - 1] + input;
	}
	
	for(int i = K; i <= N; i++){
		ret = max( ret, psum[i] - psum [i - K] );
	}
	
	cout << ret;

	return 0;
}