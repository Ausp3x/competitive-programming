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

int MOD = 1000000007;

void solve(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> A(26);
    for (int &a : A)
        cin >> a;

    // ith char, j-length substr
    vector<vector<pair<lng, int>>> dp(n, vector<pair<lng, int>>(n + 1, {0, INF32}));
    vector<vector<vector<bool>>> chrs(n, vector<vector<bool>>(n + 1, vector<bool>(26, 0)));
    dp[0][1].fi = 1;
    dp[0][1].se = 1;
    chrs[0][1][s[0] - 'a'] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][1].fi += dp[i - 1][j].fi;
            dp[i][1].fi %= MOD;
            dp[i][1].se = min(dp[i][1].se, dp[i - 1][j].se + 1);
        }
        chrs[i][1][s[i] - 'a'] = true;
    
        for (int j = 2; j <= n; j++) {
            if (dp[i - 1][j - 1].fi == 0)
                continue; 

            bool chk = true;
            for (int k = 0; k < 26; k++) {
                if (!(chrs[i - 1][j - 1][k] || (char('a' + k) == s[i])))
                    continue;

                if (j > A[k]) {
                    chk = false;
                    break;
                }
            }

            if (!chk)
                continue;

            dp[i][j] = dp[i - 1][j - 1];
            for (int k = 0; k < 26; k++) {
                chrs[i][j][k] = chrs[i - 1][j - 1][k];
                if (s[i] - 'a' == k)
                    chrs[i][j][k] = true;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 1; j <= n; j++)
    //         cout << dp[i][j].fi << ' ';
    //     cout << endl;
    // }

    lng ans = 0;
    for (int j = 1; j <= n; j++) {
        ans += dp[n - 1][j].fi;
        ans %= MOD;
    }
    int max_len = 0;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n; j++)
            if (dp[i][j].fi > 0)
                max_len = max(max_len, j);
    int min_str = INF32;
    for (int j = 1; j <= n; j++)
        min_str = min(min_str, dp[n - 1][j].se);

    cout << ans << endl;
    cout << max_len << endl;
    cout << min_str << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}