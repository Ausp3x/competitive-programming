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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adjl(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adjl[u].pb(v);
        adjl[v].pb(u);
    }

    vector<int> D(n + 1);
    vector<array<int, 2>> H(n + 1);
    vector<vector<int>> up(n + 1, vector<int>(20));
    function<void(int, int)> dfs = [&](int cur, int prv) {
        D[cur] = D[prv] + 1;
        up[cur][0] = prv;
        for (int i = 1; i < 20; i++)
            up[cur][i] = up[up[cur][i - 1]][i - 1];
        for (int nxt : adjl[cur]) {
            if (nxt == prv)
                continue;

            dfs(nxt, cur);

            H[cur][1] = max(H[cur][1], H[nxt][0] + 1);
            if (H[cur][1] > H[cur][0])
                swap(H[cur][1], H[cur][0]);
        }

        return;
    };

    dfs(1, 0);

    vector<vector<int>> dp(n + 1, vector<int>(20, -INF32));
    function<void(int, int)> dfs2 = [&](int cur, int prv) {
        for (int nxt : adjl[cur]) {
            if (nxt == prv)
                continue;

            dp[nxt][0] = (H[cur][0] == H[nxt][0] + 1 ? H[cur][1] : H[cur][0]) - D[cur];
            for (int i = 1; i < 20; i++)
                dp[nxt][i] = max(dp[nxt][i - 1], dp[up[nxt][i - 1]][i - 1]);

            dfs2(nxt, cur);
        }

        return;
    };

    dfs2(1, 0);

    int q;
    cin >> q;
    while (q--) {
        int u, k;
        cin >> u >> k;

        int ans = H[u][0], v = u;
        for (int i = 0; i < 20; i++)
            if (k & (1 << i)) {
                ans = max(ans, dp[v][i] + D[u]);
                v = up[v][i];
            }
        cout << ans << ' ';
    }
    cout << endl;

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