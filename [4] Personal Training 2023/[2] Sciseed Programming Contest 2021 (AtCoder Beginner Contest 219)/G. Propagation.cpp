// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adjl(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);     
        adjl[v].push_back(u);
    }

    int b = sqrt(m);
    vector<bool> is_big_node(n + 1);
    vector<int> big_nodes;
    for (int u = 1; u <= n; u++) {
        if (int(adjl[u].size()) >= b) {
            is_big_node[u] = true;
            big_nodes.push_back(u);
        }
    }

    vector<vector<int>> adjl_big(n + 1);
    for (int u = 1; u <= n; u++) {
        for (int v : adjl[u]) {
            if (is_big_node[v]) {
                adjl_big[u].push_back(v);
            }
        }
    }


    vector<pair<int, int>> x_and_ts(n + 1);
    for (int i = 1; i <= n; i++) {
        x_and_ts[i].first = i;
    }
    vector<pair<int, int>> lazy_prop_and_ts(n + 1, {-1, -1});
    for (int i = 1; i <= q; i++) {
        int u;
        cin >> u;

        for (int v : adjl_big[u]) {
            if (lazy_prop_and_ts[v].second > x_and_ts[u].second) {
                x_and_ts[u] = lazy_prop_and_ts[v];
            }
        }

        if (is_big_node[u]) {
            lazy_prop_and_ts[u] = {x_and_ts[u].first, i};
        } else {
            for (int v : adjl[u]) {
                x_and_ts[v] = {x_and_ts[u].first, i};
            }
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int v : adjl_big[u]) {
            if (lazy_prop_and_ts[v].second > x_and_ts[u].second) {
                x_and_ts[u] = lazy_prop_and_ts[v];
            }
        }
        
        cout << x_and_ts[u].first << ' ';
    }
    cout << endl;

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