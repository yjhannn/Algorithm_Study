#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int arr[10];
int result[10];
bool visited[10];
int n, m;

void solve(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && temp != arr[i])
        {
            temp = arr[i];
            result[k] = arr[i];
            visited[i] = true;
            solve(k + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    solve(0);
}