// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve(int t) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    for (int j = 0; j < m; j += 3)
        for (int i = 0; i < n; i++)
            grid[i][j] = 'X';

    for (int j = 1; j < m - 2; j += 3) {
        bool has_X = false;
        for (int i = 0; i < n; i++)
            if (grid[i][j] == 'X' || grid[i][j + 1] == 'X') {
                grid[i][j] = 'X';
                grid[i][j + 1] = 'X';
                has_X = true;
                break;
            }

        if (!has_X) {
            grid[0][j] = 'X';
            grid[0][j + 1] = 'X';
        }
    }

    if ((m - 1) % 3 == 2)
        for (int i = 0; i < n; i++)
            if (grid[i][m - 1] == 'X')
                grid[i][m - 2] = 'X';
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];
        cout << endl;
    }
    // cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}