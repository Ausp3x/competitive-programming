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

    int max_dis = 0, root = 1;
    function<void(int, int, int)> findFurthest = [&](int cur, int prv, int dis) {
        if (dis > max_dis) {
            root = cur; 
            max_dis = dis;
        }

        for (int nxt : adjl[cur]) {
            if (nxt == prv)
                continue;

            findFurthest(nxt, cur, dis + 1);
        }

        return;
    };

    findFurthest(1, -1, 0);

    vector<int> par(n + 1, -1), height(n + 1, 1), best_child(n + 1, -1);
    function<void(int, int)> dfs = [&](int cur, int prv) {
        par[cur] = prv;

        int h_max = 0;
        vector<pair<int, int>> V;
        for (int nxt : adjl[cur]) {
            if (nxt == prv)
                continue;

            dfs(nxt, cur);

            h_max = max(h_max, height[nxt]);
            V.pb({height[nxt], nxt});
        }

        height[cur] += h_max;

        sort(V.begin(), V.end(), greater<pair<int, int>>());
        if (!V.empty())
            best_child[cur] = V[0].se;
        
        return;
    };

    dfs(root, -1);

    vector<pair<int, int>> V;
    for (int i = 1; i <= n; i++)
        V.pb({height[i], i});

    sort(V.begin(), V.end());

    int val = 1;
    vector<bool> vst(n + 1);
    vector<int> ans(n + 1, -1);
    while (!V.empty()) {
        if (vst[V.back().se]) {
            V.pop_back();
            continue;
        }

        int cur = V.back().se;
        if (par[cur] != -1) {
            val = max(val, ans[par[cur]] + 4);
            if ((val - ans[par[cur]]) % 2 != 0)
                val++;
        }

        vst[cur] = true;
        ans[cur] = val;
        val++;
        while (best_child[cur] != -1) {
            cur = best_child[cur];
            vst[cur] = true;
            ans[cur] = val;
            val++;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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