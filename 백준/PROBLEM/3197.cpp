#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int visited_l[1501][1501], visited[1501][1501], n, m, day = 0, lx, ly, x, y;
char a[1501][1501];
string s;
queue<pair<int, int> > water, water_temp, swan, swan_temp;

void queue_clear(queue<pair<int, int> > &q) {
  queue<pair<int, int> > ex;
  swap(q, ex);
}

void melt() {
  int mx, my;
  while(water.size()) {
    mx = water.front().first;
    my = water.front().second;
    water.pop();
    for(int i = 0; i < 4; i++) {
      int nx = mx + dx[i];
      int ny = my + dy[i];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) 
        continue;
      if(a[nx][ny] == 'X') {
        visited[nx][ny] = 1;
        water_temp.push(make_pair(nx, ny));
        a[nx][ny] = '.';
      }
    }
  }
}

bool move() {
  while(swan.size()) {
    x = swan.front().first;
    y = swan.front().second;
    swan.pop();
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited_l[nx][ny]) 
        continue;
      visited_l[nx][ny] = 1;
      if(a[nx][ny] == '.')
        swan.push(make_pair(nx, ny));
      if(a[nx][ny] == 'X')
        swan_temp.push(make_pair(nx, ny));
      else if(a[nx][ny] == 'L')
        return true;
    }
  }
  return false;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s;
    for(int j = 0; j < m; j++) {
      a[i][j] = s[j];
      if(a[i][j] == 'L') {
        lx = i;
        ly = j;
      }
      if(a[i][j] == '.' || a[i][j] == 'L') {
        visited[i][j] = 1;
        water.push(make_pair(i, j));
      }
    }
  }
  swan.push(make_pair(lx, ly));
  visited_l[lx][ly] = 1;
  while(1) {
    if(move()) 
      break;
    melt();
    water = water_temp;
    swan = swan_temp;
    queue_clear(water_temp);
    queue_clear(swan_temp);
    day++;
  }
  cout << day;
  return 0;
}