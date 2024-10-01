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
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int n, l;
vector<vector<int>> adjl;

int timer;
vector<int> t_in, t_out;
vector<int> depths;
vector<vector<int>> up;

void initBinaryLifting(int u, int prv, int dep) {
    t_in[u] = timer;
    
    depths[u] = dep;
    up[u][0] = prv;
    for (int i = 1; i <= l; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v : adjl[u]) {
        if (v == prv)
            continue;

        timer++;
        initBinaryLifting(v, u, dep + 1);
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
    int n;
    cin >> n;
    l = ceil(log2(n));
    adjl.clear();
    adjl.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjl[u].pb(v);
        adjl[v].pb(u);
    }

    timer = 0;
    t_in.clear();
    t_in.resize(n + 1);
    t_out.clear();
    t_out.resize(n + 1);
    depths.clear();
    depths.resize(n + 1);
    up.clear();
    up.resize(n + 1, vector<int>(l + 1, 1));
    initBinaryLifting(1, 1, 0);

    // for (int x : depths)
    //     cout << x << ' ';
    // cout << endl;

    // for (int i = 0; i <= n; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j <= l; j++)
    //         cout << up[i][j] << ' ';
    //     cout << endl;
    // }

    int q;
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        
        int cab = LCA(a, b);
        int d1 = depths[a] + depths[b] - 2 * depths[cab];

        int cax = LCA(a, x), cby = LCA(b, y);
        int d2 = depths[a] + depths[x] - 2 * depths[cax] + depths[b] + depths[y] - 2 * depths[cby] + 1;

        int cbx = LCA(b, x), cay = LCA(a, y);
        int d3 = depths[b] + depths[x] - 2 * depths[cbx] + depths[a] + depths[y] - 2 * depths[cay] + 1;

        // cout << cab << ", " << cax << ' ' << cby << ", " << cbx << ' ' << cay << endl;
        // cout << d1 << ' ' << d2 << ' ' << d3 << endl;

        if (d1 <= k && d1 % 2 == k % 2) {
            cout << "YES" << endl;
            continue;
        }

        if (d2 <= k && d2 % 2 == k % 2) {
            cout << "YES" << endl;
            continue;
        }

        if (d3 <= k && d3 % 2 == k % 2) {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
     
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