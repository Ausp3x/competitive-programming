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

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int k;
vector<vector<pair<int, int>>> adjl;
map<pair<int, int>, int> edg_idx;

lng G = 0, B = 0;
vector<bool> vst;
vector<int> sze;

void bfs(int u) {
    vst[u] = true;
    sze[u] = 1;
    for (auto [v, w] : adjl[u]) {
        if (vst[v])
            continue;

        bfs(v);
        sze[u] += sze[v];
        if (sze[v] % 2 != 0)
            G += w;
        B += 1ll * min(sze[v], 2 * k - sze[v]) * w;
    }

    return;
}

void solve() {
    cin >> k;
    adjl.clear();
    adjl.resize(2 * k);
    for (int i = 0; i < 2 * k - 1; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;

        adjl[a].pb({b, t});
        adjl[b].pb({a, t});   
        edg_idx[{a, b}] = i;
        edg_idx[{b, a}] = i;
    }
    
    G = 0;
    B = 0;
    vst.clear();
    vst.resize(2 * k);
    sze.clear();
    sze.resize(2 * k, -1);
    bfs(0);

    cout << G << ' ' << B << endl;

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