#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
char a[51][51];
int dp[51][51];
bool visited[51][51];
bool infinite = false;

int dfs(int x, int y) {
    if (infinite) return 0;
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (a[x][y] == 'H') return 0;
    if (visited[x][y]) {
        infinite = true;
        return 0;
    }
    if (dp[x][y]) return dp[x][y];
    visited[x][y] = true;
    int maxMoves = 0;
    int steps = a[x][y] - '0';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i] * steps;
        int ny = y + dy[i] * steps;
        maxMoves = max(maxMoves, dfs(nx, ny));
    }
    visited[x][y] = false;
    return dp[x][y] = maxMoves + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            a[i][j] = str[j];
        }
    }
    int ans = dfs(0, 0);
    if (infinite) cout << -1;
    else cout << ans;
    return 0;
}