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

// TODO: Fenwick Tree
// TODO: Sprague-Grundy
// TODO: Bellman Ford
// TODO: Floyd Warshall
// TODO: Ford Fulkerson + its optimization
// TODO: Kosaraju
// TODO: center of tree
// TODO: centroid of tree
// TODO: AHU algorithm



// TESTED
template<class T> 
lng kadane(const vector<T> &arr) {
    lng max_sum = -INF64, cur_sum = -INF64;
    for (T a : arr) {
        cur_sum = max(cur_sum + a, lng(a));
        max_sum = max(max_sum, cur_sum);
    }

    return max_sum;
}



// TESTED
lng modPow(lng x, lng y, lng mod) {
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

    Dijkstra(int n): n(n) {
        is_proc.resize(n + 1);
        dis.resize(n + 1, INF64);
    }

    void runDijkstra(const vector<int> &src, const vector<vector<pair<int, int>>> &adjl) {
        fill(is_proc.begin(), is_proc.end(), false);
        fill(dis.begin(), dis.end(), INF64);
        
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
        };

        return;
    }
};



struct EdmondsKarp {
    int n;
    lng max_flow = 0, add_flow = 0;
    vector<int> par;
    vector<vector<bool>> oadj;
    vector<vector<int>> adjl;
    vector<vector<lng>> ocap, ncap; // (n + 1) × (n + 1)

    vector<bool> in_S;
    set<pair<int, int>> matches;
    vector<vector<int>> adjl_copy, end_idxs, paths;
    
    EdmondsKarp(int n, const vector<vector<int>> &adjl, const vector<vector<lng>> &cap): n(n), ocap(cap) {
        assert(ocap.size() == n + 1);
        for (int i = 0; i <= n; i++) {
            assert(ocap[i].size() == n + 1);
        }

        oadj.resize(n + 1, vector<bool>(n + 1));
        vector<set<int>> distinct_adjl(n + 1);
        for (int cur = 0; cur <= n; cur++) {
            for (int nxt : adjl[cur]) {
                oadj[cur][nxt] = true;
                distinct_adjl[cur].insert(nxt);
                distinct_adjl[nxt].insert(cur);
            }
        }

        this->adjl.resize(n + 1);
        for (int cur = 0; cur <= n; cur++) {
            for (int nxt : distinct_adjl[cur]) {
                this->adjl[cur].pb(nxt);
            }
        }

        par.resize(n + 1, -1);
        in_S.resize(n + 1);
        end_idxs.resize(n + 1);
    }

    lng augmentFlow(int s, int t) {
        fill(par.begin(), par.end(), -1);
        par[s] = s;

        queue<pair<int, lng>> q;
        q.push({s, INF64});
        while (!q.empty()) {
            auto [cur, cur_flow] = q.front();
            q.pop();

            for (int nxt : adjl[cur]) {
                if (par[nxt] == -1 && ncap[cur][nxt] > 0) {
                    par[nxt] = cur;
                    
                    lng nxt_flow = min(cur_flow, ncap[cur][nxt]);
                    if (nxt == t) {
                        return nxt_flow;
                    }
                    
                    q.push({nxt, nxt_flow});
                }
            }
        }

        return 0;
    }

    lng getMaxFlow(int s, int t, bool min_cut_flag = false, bool bipartite_max_matching_flag = false, bool all_paths_flag = false) {
        max_flow = 0;
        add_flow = 0;
        ncap = ocap;

        while (add_flow = augmentFlow(s, t)) {
            max_flow += add_flow;

            int cur = t;
            while (cur != s) {
                int prv = par[cur];
                ncap[prv][cur] -= add_flow;
                ncap[cur][prv] += add_flow;
                cur = prv;
            }
        }

        if (min_cut_flag) {
            getMinCut(s, t);
        }

        if (bipartite_max_matching_flag) {
            getBipartiteMaxMatching(s, t);
        }

        if (all_paths_flag) {
            getAllPaths(s, t);
        }

        return max_flow;
    }

    void getMinCut(int s, int t) {
        fill(in_S.begin(), in_S.end(), false);

        queue<int> q;
        q.push(s);
        in_S[s] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt : adjl[cur]) {
                if (in_S[nxt] || ncap[cur][nxt] == 0) {
                    continue;
                }

                q.push(nxt);
                in_S[nxt] = true;
            }
        }

        return;
    }

    void getBipartiteMaxMatching(int s, int t) {
        matches.clear();

        for (int cur = 0; cur <= n; cur++) {
            if (cur == s || cur == t) {
                continue;
            }

            for (int nxt : adjl[cur]) {
                if (nxt == s || nxt == t) {
                    continue;
                }

                if (oadj[cur][nxt] && ncap[cur][nxt] == 0) {
                    matches.insert({cur, nxt});
                }
            }
        }

        return;
    }

    void getAllPaths(int s, int t) {
        adjl_copy = adjl;
        for (int i = 0; i <= n; i++) {
            end_idxs[i].clear();
        }
        paths.clear();

        int cnt = 1;
        vector<bool> vst(n + 1);
        while (!adjl_copy[s].empty()) {
            int cur = adjl_copy[s].back();
            adjl_copy[s].pop_back();

            if (!oadj[s][cur] || ncap[s][cur] > 0) {
                continue;
            }

            paths.pb({s, cur});
            
            while (cur != t) {
                int nxt = adjl_copy[cur].back(); 
                adjl_copy[cur].pop_back();

                if (!oadj[cur][nxt] || ncap[cur][nxt] > 0) {
                    continue;
                }
                
                paths.back().pb(nxt);

                cur = nxt;
            }
        }
    }
};



struct EulerTourTree {
    int n, root;
    vector<lng> arr;
    vector<vector<int>> adjl;

    int timer = 0;
    vector<int> t_in, t_out, time_to_orig;
    vector<lng> euler;
    SegTree *segt;

    template<class T>
    EulerTourTree(int n, int root, const vector<T> &arr, const vector<vector<T>> &adjl) : n(n), root(root), arr(arr), adjl(adjl) {
        assert(0 <= root && root < n);
        assert(arr.size() == n && adjl.size() == n);
        t_in.resize(n);
        t_out.resize(n);
        time_to_orig.resize(n);
        euler.resize(n);
        
        dfs(root, -1);

        segt = new SegTree(0, n - 1, euler);
    }

    void dfs(int cur, int prv) {
        t_in[cur] = timer;
        time_to_orig[timer] = cur;
        euler[timer] = arr[cur];
        timer++;
        for (int nxt : adjl[cur]) {
            if (nxt == prv)
                continue;

            dfs(nxt, cur);
        }
        t_out[cur] = timer - 1;

        return;
    }

    void subtreeAddUpdate(int u, lng x, bool u_only = false) {
        segt->rangeAddUpdate(t_in[u], (u_only ? t_in[u] : t_out[u]), x);
    }

    void subtreeSetUpdate(int u, lng x, bool u_only = false) {
        segt->rangeSetUpdate(t_in[u], (u_only ? t_in[u] : t_out[u]), x);
    }

    pair<lng, int> subtreeMaxQuery(int u, bool u_only = false) {
        auto res = segt->rangeMaxQuery(t_in[u], (u_only ? t_in[u] : t_out[u]));
        res.se = time_to_orig[res.se];

        return res;
    }
    
    pair<lng, int> subtreeMinQuery(int u, bool u_only = false) {
        auto res = segt->rangeMinQuery(t_in[u], (u_only ? t_in[u] : t_out[u]));
        res.se = time_to_orig[res.se];

        return res;
    }

    lng subtreeSumQuery(int u, bool u_only = false) {
        return segt->rangeSumQuery(t_in[u], (u_only ? t_in[u] : t_out[u]));
    }
};



struct FenTree {
    
};



struct FloydWarshall {
    int n;
    vector<vector<lng>> dis;
    
    FloydWarshall(int n, vector<vector<lng>> dis) : n(n), dis(dis) {
        assert(dis.size() == n + 1);
        for (int i = 0; i <= n; i++) {
            assert(dis[i].size() == n + 1);
        }
    }
    
    void runFloydWarshall(int bgn, int end) {
        assert(0 <= bgn && bgn <= n);
        assert(0 <= end && end <= n);
        for (int k = bgn; k <= end; k++) {
            for (int i = bgn; i <= end; i++) {
                for (int j = bgn; j <= end; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
                }
            }
        }
    
        return;
    }
};



// TESTED
struct LCA {
    int n, root, l, timer = 0;
    vector<int> t_in, t_out;
    vector<vector<int>> up;

    LCA(int n, int root, const vector<vector<int>> &adjl): n(n), root(root) {
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



struct MergeSortTree {    
    int l, r;
    vector<lng> sorted;
    MergeSortTree *l_child, *r_child;

    // all values must be distinct
    template<class T> 
    MergeSortTree(int l, int r, const vector<T> &arr): l(l), r(r) {
        if (l == r) {
            sorted.clear();
            sorted.pb(arr[l]);
            l_child = r_child = nullptr;
        } else {
            int m = (l + r) / 2;
            l_child = new MergeSortTree(l, m, arr);
            r_child = new MergeSortTree(m + 1, r, arr);
            pull();
        }
    }

    // pull states up from children
    void pull() {
        if (l_child != nullptr && r_child != nullptr) {
            priority_queue<lng, vector<lng>, greater<lng>> pq;
            for (lng x : l_child->sorted)
                pq.push(x);
            for (lng x : r_child->sorted)
                pq.push(x);
        
            while (!pq.empty()) {
                sorted.pb(pq.top());
                pq.pop();
            }
        }

        return;
    }

    // 0-indexed
    int getPosInSortedSubarray(int cur_l, int cur_r, lng x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return 0;
        }

        if (cur_l <= l && r <= cur_r) {
            return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
        } 

        return l_child->getPosInSortedSubarray(cur_l, cur_r, x) + r_child->getPosInSortedSubarray(cur_l, cur_r, x);
    }

    lng rangeMedianQuery(int cur_l, int cur_r, lng l = 0, lng r = 1'000'000'000'000'000'001) {
        int req = (cur_r - cur_l + 1) / 2;
        while (r - l > 1) {
            lng md = (l + r) / 2;

            int pos = getPosInSortedSubarray(cur_l, cur_r, md);
            if (pos <= req)
                l = md;
            else 
                r = md;
        }
        
        return l;
    }
};



// TESTED
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
        if (y > x || y < 0) {
            return 0;
        }

        return fac[x] * inv_fac[y] % MOD * inv_fac[x - y] % MOD;
    }

    lng permu(int x, int y) {
        if (y > x || y < 0) {
            return 0;
        }
            
        return fac[x] * inv_fac[x - y] % MOD;
    }
};



// TODO
// struct Random {
//     Random() {}

mt19937 rng_int(chrono::steady_clock::now().time_since_epoch().count());
int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng_int);
}

mt19937_64 rng_lng(chrono::steady_clock::now().time_since_epoch().count());
lng randLng(lng l, lng r) {
    return uniform_int_distribution<lng>(l, r)(rng_lng);
}
// };



// TESTED
struct SegTree {    
    int l, r;
    lng mn = INF64, mx = -INF64, sum = 0;
    int mn_idx = -1, mx_idx = -1;
    lng add_upd = 0, set_upd = 0;
    bool set_flag = false;
    SegTree *l_child, *r_child;

    template<class T> 
    SegTree(int l, int r, const vector<T> &arr): l(l), r(r) {
        if (l == r) {
            assert(-INF64 < arr[l] && arr[l] < INF64);
            mn = mx = sum = arr[l];
            mn_idx = mx_idx = l;
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
        if (l_child != nullptr && r_child != nullptr) {
            if (set_flag) {
                l_child->add_upd = 0;
                l_child->set_upd = set_upd;
                l_child->set_flag = true;
                l_child->mn = l_child->mx = set_upd;
                l_child->sum = l_child->getRange() * set_upd;
                l_child->mn_idx = l_child->mx_idx = l_child->l;
                
                r_child->add_upd = 0;
                r_child->set_upd = set_upd;
                r_child->set_flag = true;
                r_child->mn = r_child->mx = set_upd;
                r_child->sum = r_child->getRange() * set_upd;
                r_child->mn_idx = r_child->mx_idx = r_child->l;
                
                set_upd = 0;
                set_flag = false;
            }

            if (add_upd != 0) {
                l_child->add_upd += add_upd;
                l_child->mn += add_upd;
                l_child->mx += add_upd;
                l_child->sum += l_child->getRange() * add_upd;
                
                r_child->add_upd += add_upd;
                r_child->mn += add_upd;
                r_child->mx += add_upd;
                r_child->sum += r_child->getRange() * add_upd;

                add_upd = 0;
            }
        }

        return;
    }

    // pull states up from children
    void pull() {
        assert(add_upd == 0 && set_upd == 0 && !set_flag);
        if (l_child != nullptr && r_child != nullptr) {
            if (l_child->mn <= r_child->mn) {
                mn = l_child->mn;
                mn_idx = l_child->mn_idx;
            } else {
                mn = r_child->mn;
                mn_idx = r_child->mn_idx;
            }

            if (l_child->mx >= r_child->mx) {
                mx = l_child->mx;
                mx_idx = l_child->mx_idx;
            } else {
                mx = r_child->mx;
                mx_idx = r_child->mx_idx;
            }

            sum = l_child->sum + r_child->sum;
        }

        return;
    }

    void rangeAddUpdate(int cur_l, int cur_r, lng x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        }
        
        if (cur_l <= l && r <= cur_r) {
            if (set_flag) {
                set_upd += x;
            } else { 
                add_upd += x; 
            }
            mn += x;
            mx += x;
            sum += getRange() * x;            
            return;
        }
        
        push();
        l_child->rangeAddUpdate(cur_l, cur_r, x);
        r_child->rangeAddUpdate(cur_l, cur_r, x);
        pull();

        return;
    }

    void rangeSetUpdate(int cur_l, int cur_r, lng x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        }
        
        if (cur_l <= l && r <= cur_r) {
            set_upd = x;
            set_flag = true;
            mn = mx = x;
            sum = getRange() * x;
            mn_idx = mx_idx = l;
            return;
        }
        
        push();
        l_child->rangeSetUpdate(cur_l, cur_r, x);
        r_child->rangeSetUpdate(cur_l, cur_r, x);
        pull();

        return;
    }

    pair<lng, int> rangeMaxQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return {-INF64, -1};
        }

        if (cur_l <= l && r <= cur_r) {
            return {mx, mx_idx};
        }
        
        push();
        auto l_res = l_child->rangeMaxQuery(cur_l, cur_r);
        auto r_res = r_child->rangeMaxQuery(cur_l, cur_r);
        if (l_res.fi >= r_res.fi) {
            return l_res;
        } else {
            return r_res;
        }
    }

    pair<lng, int> rangeMinQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return {INF64, -1};
        }

        if (cur_l <= l && r <= cur_r) {
            return {mn, mn_idx};
        }
        
        push();
        auto l_res = l_child->rangeMinQuery(cur_l, cur_r);
        auto r_res = r_child->rangeMinQuery(cur_l, cur_r);
        if (l_res.fi <= r_res.fi) {
            return l_res;
        } else {
            return r_res;
        }
    }

    lng rangeSumQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return 0;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            return sum;
        } 
        
        push();

        return l_child->rangeSumQuery(cur_l, cur_r) + r_child->rangeSumQuery(cur_l, cur_r);
    }

    lng getRange() {
        return r - l + 1;
    }
};



// TESTED
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