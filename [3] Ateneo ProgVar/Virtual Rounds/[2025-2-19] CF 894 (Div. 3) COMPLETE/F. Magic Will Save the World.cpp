// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O3, fast-math")
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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    lng a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    vector<int> S(n + 1);
    vector<int> S_sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
        S_sum[i] = S_sum[i - 1] + S[i];
    }

    if (a >= 1'000'000 || b >= 1'000'000) {
        cout << 1 << endl;
        return;
    }

    if (a < b)
        swap(a, b);

    vector<vector<bool>> dp(2, vector<bool>(S_sum[n] + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int prv = (i & 1) ^ 1;
        int cur = (i & 1);

        for (int j = 0; j <= S_sum[i - 1]; j++) {
            if (!dp[prv][j])
                continue;

            dp[cur][j] = dp[prv][j];
            dp[cur][j + S[i]] = dp[prv][j];
        }
    }

    int ans = INF32, cur = n & 1;
    for (int i = 0; i <= S_sum[n]; i++) {
        if (!dp[cur][i])
            continue;

        int t = max((i + a - 1) / a, (S_sum[n] - i + b - 1) / b);
        ans = min(ans, t);
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