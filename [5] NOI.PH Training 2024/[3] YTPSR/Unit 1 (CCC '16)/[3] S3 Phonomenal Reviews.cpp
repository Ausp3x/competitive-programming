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
    int p_0 = INF32;
    vector<int> is_pho(n);
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;

        p_0 = min(p_0, p);
        is_pho[p] = true;
    }

    if (p_0 == INF32) {
        cout << -1 << endl;
        return;
    }

    vector<pair<int, int>> edgl;
    vector<vector<int>> adjl(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        
        edgl.pb({u, v});
        adjl[u].pb(v);
        adjl[v].pb(u);
    }

    // prune nodes that will never be crossed
    vector<bool> is_necessary(n);
    function<void(int, int)> dfsPrune = [&](int cur, int prv) {
        int chk = is_pho[cur];
        for (int nxt : adjl[cur]) {
            if (nxt == prv)
                continue;

            dfsPrune(nxt, cur);
            chk |= is_necessary[nxt];
        }
        is_necessary[cur] = chk;
        
        return;
    };

    dfsPrune(p_0, p_0);

    // cout << p_0 << endl;
    // for (int x : is_necessary)
    //     cout << x << ' ';
    // cout << endl;

    int ans = 2 * accumulate(is_necessary.begin(), is_necessary.end(), 0) - 2;
    
    // cout << ans << endl;

    // get diameter of the remaining tree
    vector<vector<int>> adjl_pruned(n);
    for (auto &[u, v] : edgl) {
        if (!is_necessary[u] || !is_necessary[v])
            continue;

        adjl_pruned[u].pb(v);
        adjl_pruned[v].pb(u);
    }

    // cout << p_0 << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (int j : adjl_pruned[i])
    //         cout << j << ' ';
    //     cout << endl;
    // }

    int node = -1, dep_max = -1;
    function<void(int, int, int)> dfsDeepest = [&](int cur, int prv, int dep) {
        if (dep > dep_max) {
            node = cur;
            dep_max = dep;
        }
        
        for (int nxt : adjl_pruned[cur]) {
            if (nxt == prv)
                continue;

            dfsDeepest(nxt, cur, dep + 1);
        }
    };

    dfsDeepest(p_0, p_0, 0);

    // cout << node << ' ' << dep_max << endl

    dep_max = -1;
    dfsDeepest(node, node, 0);

    // cout << node << ' ' << dep_max << endl;

    // subtract the diameter from 2 * (no. of edges)
    cout << ans - dep_max << endl;

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