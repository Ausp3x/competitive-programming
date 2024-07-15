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
    int n;
    cin >> n;
    vector<vector<char>> grid(2, vector<char>(n));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    string ans;
    vector<vector<lng>> dp(2, vector<lng>(n, 0));
    ans += grid[0][0];
    dp[0][0] = 1;
    for (int j = 1; j < n; j++) {
        dp[0][j] += dp[0][j - 1];
        dp[1][j - 1] += dp[0][j - 1];
        if (j > 1)
            dp[1][j - 1] += dp[1][j - 2];


        if ((grid[0][j] == '0' && dp[0][j] > 0) || (grid[1][j - 1] == '0' && dp[1][j - 1] > 0)) {
            ans += '0';
            dp[0][j] *= (grid[0][j] == '0');
            dp[1][j - 1] *= (grid[1][j - 1] == '0');
        } else
            ans += '1';
    }
    ans += grid[1][n - 1];
    dp[1][n - 1] += dp[0][n - 1] + dp[1][n - 2];

    cout << ans << endl;
    cout << dp[1][n - 1] << endl;

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