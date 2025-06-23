// 백트래킹??
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dice[10], loc[4], v[101];
vector<int> adj[50];

int move(int here, int cnt) {
  if(here == 100)
    return 100;
  if(adj[here].size() >= 2) {
    here = adj[here][1];
    cnt--;
  }
  if(cnt > 0) {
    queue<int> q;
    q.push(here);
    int there;
    while(q.size())
    {
      int top = q.front();
      q.pop();
      there = adj[top][0];
      q.push(there);
      if(there == 100)
        break;
      cnt--;
      if(cnt == 0)
        break;
    }
    return there;
  }
  else
    return here;
}

bool isCheck(int mal, int idx) {
  if(mal == 100)
    return false;
  for(int i = 0; i < 4; i++) {
    if(idx == i)
      continue;
    if(loc[i] == mal)
      return true;
  }
  return false;
}

void add(int num, int val) {
  adj[num].push_back(val);
}

void map_setting() {
  for(int i = 0; i <= 19; i++) add(i, i + 1); 
	add(5, 21); add(21, 22); add(22, 23); add(23, 24); 
	add(15, 29); add(29, 30); add(30, 31);add(31, 24); 

	add(10, 27); add(27, 28); add(28, 24); add(24, 25); 
	add(25, 26); add(26, 20); add(20, 100);  

  v[1] = 2; v[2] = 4;  v[3] = 6; v[4] = 8; v[5] = 10; 
	v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20; 
	v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30; 
	v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40; 
	v[21] = 13; v[22] = 16; v[23] = 19;  v[24] = 25; 
	v[27] = 22; v[28] = 24; v[25] = 30; v[26] = 35; 
	v[29] = 28; v[30] = 27; v[31] = 26; 
}

int go(int here) {
  if(here == 10)
    return 0;
  int ret = 0;
  for(int i = 0; i < 4; i++) {
    int tmp = loc[i];
    int mal = move(tmp, dice[here]);
    if(isCheck(mal, i))
      continue;
    loc[i] = mal;
    ret = max(ret, go(here + 1) + v[mal]);
    loc[i] = tmp;
  }
  return ret;
}

int main() {
  map_setting();
  for(int i = 0; i < 10; i++) {
    cin >> dice[i];
  }
  cout << go(0);
  return 0;
}