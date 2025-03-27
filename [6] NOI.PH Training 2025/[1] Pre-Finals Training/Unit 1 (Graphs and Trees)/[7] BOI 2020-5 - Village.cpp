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
    int n;
    cin >> n;
    vector<vector<int>> adjl(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adjl[u].pb(v);
        adjl[v].pb(u);
    }

    vector<int> mn_idx(n + 1), mx_idx(n + 1);
    for (int i = 1; i <= n; i++) {
        mn_idx[i] = i;
        mx_idx[i] = i;
    }

    lng mn = 0, mx = 0;
    vector<int> sizes(n + 1), dfs_ord;
    auto dfs = [&](int cur, int prv, auto &&dfs) {
        if (false) return;
        
        sizes[cur] = 1;
        dfs_ord.pb(cur);
        for (int nxt : adjl[cur]) {
            if (nxt == prv)
                continue;

            dfs(nxt, cur, dfs);

            sizes[cur] += sizes[nxt];
            mx += 2 * min(n - sizes[nxt], sizes[nxt]);
        }

        if (mn_idx[cur] == cur) {
            if (prv == -1)
                swap(mn_idx[cur], mn_idx[adjl[cur][0]]);
            else
                swap(mn_idx[cur], mn_idx[prv]);

            mn += 2;
        }

        return;
    };

    dfs(1, -1, dfs);
    for (int i = 1; i <= n; i++)
        mx_idx[dfs_ord[i - 1]] = dfs_ord[(i - 1 + n / 2) % n];

    cout << mn << ' ' << mx << endl;
    for (int i = 1; i <= n; i++)
        cout << mn_idx[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++)
        cout << mx_idx[i] << " \n"[i == n];

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