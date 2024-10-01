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
    int n;
    cin >> n;
    bool is_all_x = true;
    vector<vector<char>> grid(2, vector<char>(n));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            is_all_x &= grid[i][j] == 'x';
        }

    if (is_all_x) {
        cout << 0 << endl;
        return;
    }

    int ans = 0;
    for (int j = 1; j < n - 1; j++) {
        if (grid[0][j - 1] == 'x' && grid[0][j] == '.' && grid[0][j + 1] == 'x' &&
            grid[1][j - 1] == '.' && grid[1][j] == '.' && grid[1][j + 1] == '.')
            ans++;
        
        if (grid[0][j - 1] == '.' && grid[0][j] == '.' && grid[0][j + 1] == '.' &&
            grid[1][j - 1] == 'x' && grid[1][j] == '.' && grid[1][j + 1] == 'x')
            ans++;
    }

    cout << ans << endl;
    
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