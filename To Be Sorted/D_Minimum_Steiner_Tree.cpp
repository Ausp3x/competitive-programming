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
typedef __int128     lli;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int N, L;
vector<vector<int>> adjl;

int timer;
vector<int> t_in, t_out;
vector<vector<int>> up;

void initBinaryLifting(int u, int prv) {
    t_in[u] = timer;

    up[u][0] = prv;
    for (int i = 1; i <= L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v : adjl[u]) {
        if (v == prv)
            continue;

        timer++;
        initBinaryLifting(v, u);
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

    for (int i = L; i >= 0; i--)
        if (!isAncestor(up[u][i], v))
            u = up[u][i];

    return up[u][0];
}

void solve() {
    int K;
    cin >> N >> K;
    L = ceil(log2(N));
    adjl.clear();
    adjl.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        adjl[u].pb(v);
        adjl[v].pb(u);
    }
    vector<int> V(K);
    for (int &v : V)
        cin >> v;

    if (K == 1) {
        cout << 1 << endl;
        return;
    }

    timer = 0;
    t_in.clear();
    t_in.resize(N + 1);
    t_out.clear();
    t_out.resize(N + 1);
    up.clear();
    up.resize(N + 1, vector<int>(L + 1, 1));
    initBinaryLifting(1, 1);

    int lca = LCA(V[0], V[1]);
    for (int i = 2; i < K; i++)
        lca = LCA(lca, V[i]);

    vector<bool> vst(N + 1);
    vst[lca] = true;
    for (int v : V) {
        while (!vst[v]) {
            // cout << v << ' ';

            vst[v] = true;
            v = up[v][0];
        }
    }
    // cout << endl;

    // for (int i = 1; i <= N; i++) 
    //     if (vst[i])
    //         cout << i << ' ';
    // cout << endl;

    assert(vst[0] == 0);
    cout << accumulate(vst.begin(), vst.end(), 0) << endl;

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