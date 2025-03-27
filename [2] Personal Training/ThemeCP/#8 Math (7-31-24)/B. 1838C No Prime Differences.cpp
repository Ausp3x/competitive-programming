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

void solve() {
    int n, m;
    cin >> n >> m;

    if (n == 4) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << j * n + i + 1 << ' ';
            cout << endl;
        }

        return;
    }

    vector<int> ord;
    for (int i = 0; i < n; i += 2)
        ord.pb(i);
    for (int i = 1; i < n; i += 2)
        ord.pb(i);

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            grid[ord[i]][j] = i * m + j + 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << grid[i][j] << ' ';
        cout << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}