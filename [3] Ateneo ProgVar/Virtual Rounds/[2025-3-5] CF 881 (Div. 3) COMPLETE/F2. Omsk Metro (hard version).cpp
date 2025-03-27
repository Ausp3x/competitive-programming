// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O3, fast-math")
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

struct Node {
    int root = -1, sum = 0;
    int prf_mx = 0, suf_mx = 0, mx = 0;
    int prf_mn = 0, suf_mn = 0, mn = 0;

    void init(int u, int x) {
        root = u;
        sum = x;
        prf_mx = suf_mx = mx = max(0, x);
        prf_mn = suf_mn = mn = min(0, x);

        return;
    }

    void combine(const Node &l, const Node &r) {
        root = l.root;
        sum = l.sum + r.sum;
        prf_mx = max({0, l.prf_mx, l.sum + r.prf_mx});
        suf_mx = max({0, r.suf_mx, r.sum + l.suf_mx});
        mx = max({0, l.mx, r.mx, l.suf_mx + r.prf_mx});
        prf_mn = min({0, l.prf_mn, l.sum + r.prf_mn});
        suf_mn = min({0, r.suf_mn, r.sum + l.suf_mn});
        mn = min({0, l.mn, r.mn, l.suf_mn + r.prf_mn});

        return;
    }

    void print() {
        cout << "//////////////////////////////" << endl;
        cout << root << ' ' << sum << endl;
        cout << prf_mx << ' ' << suf_mx << ' ' << mx << endl;
        cout << prf_mn << ' ' << suf_mn << ' ' << mn << endl;
        cout << "//////////////////////////////" << endl;

        return;
    }
};

struct LCA {
    int root, n, l, timer = 0;
    vector<int> t_in, t_out;
    vector<vector<Node>> up;

    vector<Node> X;
    vector<vector<int>> adjl;

    LCA(int root, int n, vector<Node> X, vector<vector<int>> adjl): root(root), n(n), X(X), adjl(adjl) {
        l = ceil(log2(n));
        t_in.resize(n + 1);
        t_out.resize(n + 1);
        up.resize(n + 1, vector<Node>(l + 1));

        init(root, -1);
    }

    void init(int cur, int prv) {
        t_in[cur] = timer;
        
        if (prv != -1)
            up[cur][0] = X[prv];
        for (int i = 1; i <= l; i++) {
            if (up[cur][i - 1].root != -1) {
                up[cur][i].combine(up[up[cur][i - 1].root][i - 1], up[cur][i - 1]);
            }
        }

        for (int nxt : adjl[cur]) {
            if (nxt == prv) {
                continue;
            }

            timer++;
            init(nxt, cur);
        }

        t_out[cur] = timer;

        return;
    }

    bool isAncestor(int u, int v) {
        if (u == -1)
            return true;

        return t_in[u] <= t_in[v] && t_out[v] <= t_out[u];
    }

    int getKthAncestor(int u, int k) {
        if (k <= 0) {
            return u;
        }
        
        if (k >= (1 << (l + 1))) {
            return -1;
        }
        
        for (int i = l; i >= 0; i--) {
            if (k & (1 << i)) {
                u = up[u][i].root;
            }
        }

        return u;
    }

    int getLCA(int u, int v) {
        if (isAncestor(u, v)) {
            return u;
        }
        
        if (isAncestor(v, u)) {
            return v;
        }

        for (int i = l; i >= 0; i--) {
            if (!isAncestor(up[u][i].root, v)) {
                u = up[u][i].root;
            }
        }

        return up[u][0].root;
    }

    pair<int, int> getRange(int u, int v) {
        if (u == v)
            return {X[u].mx, X[u].mn};
        
        int lca = getLCA(u, v);

        Node L = X[u];
        for (int i = l; i >= 0; i--) {
            if (isAncestor(up[L.root][i].root, lca)) {
                continue;
            }
            
            Node L_old = L;
            L.combine(up[L.root][i], L_old);
        }

        Node R = X[v];
        for (int i = l; i >= 0; i--) {
            if (isAncestor(up[R.root][i].root, lca))
                continue;

            Node R_old = R;
            R.combine(up[R.root][i], R_old);
        }

        if (L.root != lca && R.root != lca) {
            Node L_old = L;
            L.combine(up[L.root][0], L_old);
        }

        L.root = u;
        swap(L.prf_mx, L.suf_mx);
        swap(L.prf_mn, L.suf_mn);

        Node M;
        M.combine(L, R);
    
        return {M.mx, M.mn};
    }
};

void solve() {
    int n;
    cin >> n;
    int cnt = 1;
    vector<Node> X(2);
    vector<vector<int>> adjl(2);
    X[1].init(1, 1);
    vector<tuple<int, int, int>> Q;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            int v, x;
            cin >> v >> x;
            
            cnt++;
            X.pb(Node());
            adjl.pb({});

            X[cnt].init(cnt, x);
            adjl[v].pb(cnt);
            adjl[cnt].pb(v);            
        } else if (c == '?') {
            int u, v, k;
            cin >> u >> v >> k;

            Q.pb({u, v, k});
        }
    }

    LCA f(1, cnt, X, adjl);

    for (auto [u, v, k] : Q) {
        auto [mx, mn] = f.getRange(u, v);

        // cout << mn << ' ' << mx << endl;
        
        cout << (mn <= k && k <= mx ? "YES" : "NO") << endl;
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