#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int x, y;
    vector<pair<int, int>> pos;
    vector<pair<int, int>>::iterator iter;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pos.push_back(make_pair(y, x));
    }
    sort(pos.begin(), pos.end());
    for (iter = pos.begin(); iter != pos.end(); iter++) {
        cout << iter->second << ' ' << iter->first << '\n';
    }
}