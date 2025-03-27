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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int n, l;
vector<vector<int>> adjl;

int timer;
vector<int> t_in, t_out;
vector<vector<int>> up;

void initBinaryLifting(int u) {
    t_in[u] = timer;
    
    for (int i = 1; i <= l; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v : adjl[u]) {
        timer++;
        initBinaryLifting(v);
    }

    t_out[u] = timer;

    return;
}

bool isAncestor(int u, int v) {
    return t_in[u] <= t_in[v] && t_out[v] <= t_out[u];
}

int LCA(int u, int v) {
    if (isAncestor(u, v))
        return u;
    
    if (isAncestor(v, u))
        return v;

    for (int i = l; i >= 0; i--)
        if (!isAncestor(up[u][i], v))
            u = up[u][i];

    return up[u][0];
}

void solve() {
    int q;
    cin >> n >> q;
    l = ceil(log2(n));
    adjl.clear();
    adjl.resize(n + 1);
    up.clear();
    up.resize(n + 1, vector<int>(l + 1));
    adjl[0].pb(1);
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;

        adjl[a].pb(i);
        up[i][0] = a;
    }

    timer = 0;
    t_in.clear();
    t_in.resize(n + 1);
    t_out.clear();
    t_out.resize(n + 1);
    initBinaryLifting(0);

    vector<int> P(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> P[i];

    int ok_cnt = 0;
    vector<bool> ok(n + 1);
    for (int i = 1; i <= n; i++) {
        ok[i] = LCA(P[i - 1], P[i]) == up[P[i]][0];
        ok_cnt += ok[i];
    }

    while (q--) {
        int x, y;
        cin >> x >> y;

        swap(P[x], P[y]);

        bool chk = LCA(P[x - 1], P[x]) == up[P[x]][0];
        ok_cnt += chk - ok[x];
        ok[x] = chk;

        chk = LCA(P[y - 1], P[y]) == up[P[y]][0];
        ok_cnt += chk - ok[y];
        ok[y] = chk;

        if (x + 1 <= n) {
            chk = LCA(P[x], P[x + 1]) == up[P[x + 1]][0];
            ok_cnt += chk - ok[x + 1];
            ok[x + 1] = chk;
        }

        if (y + 1 <= n) {
            chk = LCA(P[y], P[y + 1]) == up[P[y + 1]][0];
            ok_cnt += chk - ok[y + 1];
            ok[y + 1] = chk;
        }

        cout << (ok_cnt == n ? "YES" : "NO") << endl;
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