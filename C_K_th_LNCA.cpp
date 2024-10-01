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

int n;
vector<vector<int>> adjl;

vector<int> depths;
void getDepths(int cur, int prv) {
    depths[cur] = depths[prv] + 1;

    for (int nxt : adjl[cur]) {
        if (nxt == prv)
            continue;
        
        getDepths(nxt, cur);
    }

    return;
}

void solve() {
    int q;
    cin >> n >> q;
    adjl.clear();
    adjl.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adjl[u].pb(v);
        adjl[v].pb(u);
    }

    depths.clear();
    depths.resize(n + 1);
    getDepths(1, 0);

    while (q--) {
        int k, m;
        cin >> k >> m;
        vector<bool> is_selected(n + 1);
        for (int i = 0; i < m; i++) {
            int v;
            cin >> v;

            is_selected[v] = true;
        }

        vector<int> cnts(n + 1);
        function<void(int, int)> getCnts = [&](int cur, int prv) {
            cnts[cur] += is_selected[cur];
            
            for (int nxt : adjl[cur]) {
                if (nxt == prv)
                    continue;

                getCnts(nxt, cur);
                cnts[cur] += cnts[nxt];
            }
            
            return;
        };

        getCnts(1, 0);

        map<int, int> M;
        for (int i = 1; i <= n; i++) {
            if (cnts[i] >= k)
                M[depths[i]]++;
        }

        if (M.empty()) {
            cout << 0 << endl;
            continue;
        }

        cout << M.rbegin()->se << endl;
    }
    
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