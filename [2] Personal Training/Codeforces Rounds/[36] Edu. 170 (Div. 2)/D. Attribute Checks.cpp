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
typedef __int128     lll;
template<class T> 
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> R(n);
    for (int &r : R)
        cin >> r;
    R.pb(0);
    
    int cnt = 0;
    vector<int> int_reqs, str_reqs;
    // int, str
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) {
        if (R[i] == 0) {
            int_reqs.pb(INF32);
            str_reqs.pb(INF32);
            sort(int_reqs.begin(), int_reqs.end());
            sort(str_reqs.begin(), str_reqs.end());
            
            for (int j = 0; j <= cnt; j++) {
                int k = cnt - j;

                int cur = 0;
                if (j > 0)
                    cur = max(cur, dp[j - 1][k]);
                if (k > 0)
                    cur = max(cur, dp[j][k - 1]);

                int int_pass = upper_bound(int_reqs.begin(), int_reqs.end(), j) - int_reqs.begin();
                int str_pass = upper_bound(str_reqs.begin(), str_reqs.end(), k) - str_reqs.begin();

                dp[j][k] = max(dp[j][k], cur + int_pass + str_pass);
            }

            cnt++;
            int_reqs.clear();
            str_reqs.clear();
            continue;
        }

        if (R[i] > 0)
            int_reqs.pb(abs(R[i]));
        else
            str_reqs.pb(abs(R[i]));
    }

    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= m; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << endl;
    // }

    int ans = 0;
    for (int i = 0; i <= m; i++) 
        ans = max(ans, dp[i][m - i]);

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}