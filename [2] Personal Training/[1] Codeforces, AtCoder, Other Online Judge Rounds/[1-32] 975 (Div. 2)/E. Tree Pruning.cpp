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
    int n;
    cin >> n;
    vector<vector<int>> adjl(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adjl[u].pb(v);
        adjl[v].pb(u);
    }

    vector<int> par(n + 1);
    map<int, vector<int>> depths;
    function<void(int, int, int)> dfs = [&](int cur, int prv, int dep) {
        par[cur] = prv;
        depths[dep].pb(cur);

        for (int nxt : adjl[cur]) {
            if (nxt == prv)
                continue;

            dfs(nxt, cur, dep + 1);
        }
        
        return;
    };

    dfs(1, 1, 0);
    
    int ans = n - 1;
    int cur = 0, prv = 0;
    vector<bool> vst(n + 1);
    for (auto &[k, V] : depths | views::reverse) {
        if (k == 0)
            break;

        cur -= prv;
        for (int v : V) {
            while (!vst[v]) {
                cur++;
                vst[v] = true;
                v = par[v];
            }
        }

        ans = min(ans, n - cur);

        prv = V.size();
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