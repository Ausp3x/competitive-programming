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

string narek = "narek";

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> S(n);
    vector<int> cnts(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];

        for (char c : S[i])
            cnts[i] += (c == 'n' || c == 'a' || c == 'r' || c == 'e' || c == 'k');
    }

    // ends in n(0), a(1), r(2), e(3), k(4)
    vector<vector<int>> dp(n + 1, vector<int>(5, -INF32));
    dp[0][4] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (dp[i][j] == -INF32)
                continue;

            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            int k = j;
            int cnt_add = 0, cnt_end = -1;
            for (char c : S[i]) {
                if (c == narek[(k + 1) % 5]) {
                    cnt_add++;
                    if (c == 'k')
                        cnt_end = cnt_add;
 
                    k++;
                    k %= 5;
                }
            }

            dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + 2 * cnt_add - cnts[i]);
            if (cnt_end != -1)
                dp[i + 1][4] = max(dp[i + 1][4], dp[i][j] + 2 * cnt_end - cnts[i]);
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         if (dp[i][j] == -INF32)
    //             cout << "-inf" << ' ';
    //         else
    //             cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[n][4] << endl;
    
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