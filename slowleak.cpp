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

struct Dijkstra1 {
    int n;
    vector<bool> is_proc;
    vector<lng> rem;
    priority_queue<pair<lng, int>, vector<pair<lng, int>>, greater<pair<lng, int>>> unproc;

    Dijkstra1(int n, lng D, vector<bool> &is_refill, vector<vector<pair<int, int>>> &adjl): n(n) {
        is_proc.resize(n + 1);
        rem.resize(n + 1, INF64);

        rem[n] = 0;
        unproc.push({0, n});
        while (!unproc.empty()) {
            int cur = unproc.top().se;
            unproc.pop();

            if (is_proc[cur]) {
                continue;
            }
            is_proc[cur] = true;

            for (auto [nxt, w] : adjl[cur]) {
                if (max(rem[cur] - D * is_refill[cur], 0ll) + w < rem[nxt]) {
                    rem[nxt] = max(rem[cur] - D * is_refill[cur], 0ll) + w;
                    unproc.push({rem[nxt], nxt});
                }
            }

            cout << cur << ": ";
            for (lng x : rem)
                cout << x << ' ';
            cout << endl;

        }
    }
};

void solve() {  
    int n, m, t;
    lng D;
    cin >> n >> m >> t >> D;
    vector<bool> is_refill(n + 1);
    is_refill[0] = true;
    is_refill[n] = true;
    for (int i = 0; i < t; i++) {
        int r;
        cin >> r;

        is_refill[r] = true;
    }
    vector<vector<pair<int, int>>> adjl(n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;

        adjl[u].pb({v, w});
        adjl[v].pb({u, w});
    }

    Dijkstra1 djk1(n, D, is_refill, adjl);

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