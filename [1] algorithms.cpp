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

// TODO: Fenwick Tree
// TODO: Bellman Ford
// TODO: Floyd Warshall
// TODO: Ford Fulkerson + its optimization
// TODO: Kosaraju

template<class T> 
lng kadane(const vector<T> &arr) {
    lng max_sum = -INF64, cur_sum = -INF64;
    for (T a : arr) {
        cur_sum = max(cur_sum + a, lng(a));
        max_sum = max(max_sum, cur_sum);
    }

    return max_sum;
}



lng modPow(lng x, lng y, int mod) {
    lng res = 1;
    while (y > 0) {
        if (y & 1) {
            res *= x;
            res %= mod;
        }

        y >>= 1;
        x *= x;
        x %= mod;
    }

    return (res + mod) % mod;
}



struct Dijkstra {
    int n;
    vector<bool> is_proc;
    vector<lng> dis;
    priority_queue<pair<lng, int>, vector<pair<lng, int>>, greater<pair<lng, int>>> unproc;

    Dijkstra(const vector<int> &src, int n, const vector<vector<pair<int, int>>> &adjl): n(n) {
        is_proc.resize(n + 1);
        dis.resize(n + 1, INF64);

        for (int u : src) {
            dis[u] = 0;
            unproc.push({dis[u], u});
        }
        while (!unproc.empty()) {
            int cur = unproc.top().se;
            unproc.pop();

            if (is_proc[cur]) {
                continue;
            }
            is_proc[cur] = true;

            for (auto [nxt, w] : adjl[cur]) {
                if (dis[cur] + w < dis[nxt]) {
                    dis[nxt] = dis[cur] + w;
                    unproc.push({dis[nxt], nxt});
                }
            }
        }
    }

    lng getMinDistance(int u) {
        return dis[u];
    }
};



struct FenTree {
    
};



// TESTED
struct LCA {
    int root, n, l, timer = 0;
    vector<int> t_in, t_out;
    vector<vector<int>> up;

    LCA(int root, int n, const vector<vector<int>> &adjl): root(root), n(n) {
        l = ceil(log2(n));
        t_in.resize(n + 1);
        t_out.resize(n + 1);
        up.resize(n + 1, vector<int>(l + 1, -1));

        init(root, root, adjl);
    } 

    void init(int cur, int prv, const vector<vector<int>> &adjl) {
        t_in[cur] = timer;
        
        up[cur][0] = prv;
        for (int i = 1; i <= l; i++) {
            up[cur][i] = up[up[cur][i - 1]][i - 1];
        }

        for (int nxt : adjl[cur]) {
            if (nxt == prv) {
                continue;
            }

            timer++;
            init(nxt, cur, adjl);
        }

        t_out[cur] = timer;

        return;
    }

    bool isAncestor(int u, int v) {
        return t_in[u] <= t_in[v] && t_out[v] <= t_out[u];
    }

    int getKthAncestor(int u, int k) {
        if (k <= 0) {
            return u;
        }
        
        if (k >= (1 << (l + 1))) {
            return root;
        }
        
        for (int i = l; i >= 0; i--) {
            if (k & (1 << i)) {
                u = up[u][i];
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
            if (!isAncestor(up[u][i], v)) {
                u = up[u][i];
            }
        }

        return up[u][0];
    }
};



struct ModFac {
    int n, MOD;
    vector<lng> fac, inv_fac;

    ModFac(int n, int MOD): n(n), MOD(MOD) {
        fac.resize(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i;
            fac[i] %= MOD;
        }

        inv_fac.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            inv_fac[i] = modPow(fac[i], MOD - 2);
        }
    }

    lng modPow(lng x, lng y) {
        lng res = 1;
        while (y > 0) {
            if (y & 1) {
                res *= x;
                res %= MOD;
            }

            y >>= 1;
            x *= x;
            x %= MOD;
        }

        return (res + MOD) % MOD;
    }

    lng combi(int x, int y) {
        if (y > x)
            return 0;

        return fac[x] * inv_fac[y] % MOD * inv_fac[x - y] % MOD; 
    }

    lng permu(int x, int y) {
        if (y > x)
            return 0;
            
        return fac[x] * inv_fac[x - y] % MOD;
    }
};



// TODO
struct SegTree {    
    int l, r;
    lng sum = 0, upd = 0;
    SegTree *l_child, *r_child;

    template<class T> 
    SegTree(int l, int r, const vector<T> &arr): l(l), r(r) {
        if (l == r) {
            sum += arr[l];
            l_child = r_child = nullptr;
        } else {
            int m = (l + r) / 2;
            l_child = new SegTree(l, m, arr);
            r_child = new SegTree(m + 1, r, arr);
            pull();
        }
    }

    // push updates down to children
    void push() {
        sum = getTotalSum();
        if (l_child != nullptr && r_child != nullptr) {
            l_child->upd += upd;
            r_child->upd += upd;
        }
        upd = 0;

        return;
    }

    // pull states up from children
    void pull() {
        assert(upd == 0);
        if (l_child != nullptr && r_child != nullptr) {
            sum = l_child->getTotalSum() + r_child->getTotalSum();
        }

        return;
    }

    void rangeSumUpdate(int cur_l, int cur_r, lng x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            upd += x;
            return;
        }
        
        push();
        l_child->rangeSumUpdate(cur_l, cur_r, x);
        r_child->rangeSumUpdate(cur_l, cur_r, x);
        pull();
        return;
    }

    lng rangeSumQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return 0;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            return getTotalSum();
        } 
        
        push();
        return l_child->rangeSumQuery(cur_l, cur_r) + r_child->rangeSumQuery(cur_l, cur_r);
    }

    lng getTotalSum() {
        return sum + (r - l + 1) * upd;
    }

    void debugPrint(int depth = 0) {
        for (int t = 0; t < depth; t++) {
            cout << '\t';
        }
        cout << "[" << l << ", " << r << "] has sum " << sum << " and upd " << upd << endl;
        if (l_child != nullptr && r_child != nullptr) {
            l_child->debugPrint(depth + 1);
            r_child->debugPrint(depth + 1);
        }

        return;
    }
};




struct UnionFind {
    int n;
    vector<int> link, node_size, edge_size;

    UnionFind(int n): n(n) {
        link.resize(n + 1);
        iota(link.begin(), link.end(), 0);
        node_size.resize(n + 1, 1);
        edge_size.resize(n + 1);
    }

    int findSet(int u) {
        if (u == link[u]) {
            return link[u];
        }
            
        return link[u] = findSet(link[u]);
    }

    bool isSameSet(int a, int b) {
        return findSet(a) == findSet(b);
    }

    void uniteSets(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (node_size[a] < node_size[b]) {
            swap(a, b);
        }

        if (a == b) {
            edge_size[a]++;
            return;
        }

        node_size[a] += node_size[b];
        edge_size[a] += edge_size[b] + 1;
        link[b] = a;

        return;
    }
};