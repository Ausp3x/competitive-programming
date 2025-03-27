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
        assert(this->ocap.size() == this->n + 1);
        for (int i = 0; i <= this->n; i++) {
            assert(this->ocap[i].size() == this->n + 1);
        }

        this->oadj.resize(this->n + 1, vector<bool>(this->n + 1));
        vector<set<int>> distinct_adjl(this->n + 1);
        for (int cur = 0; cur <= this->n; cur++) {
            for (int nxt : adjl[cur]) {
                this->oadj[cur][nxt] = true;
                distinct_adjl[cur].insert(nxt);
                distinct_adjl[nxt].insert(cur);
            }
        }

        this->adjl.resize(this->n + 1);
        for (int cur = 0; cur <= this->n; cur++) {
            for (int nxt : distinct_adjl[cur]) {
                this->adjl[cur].pb(nxt);
            }
        }

        this->par.resize(this->n + 1, -1);
        this->in_S.resize(this->n + 1);
        this->end_idxs.resize(n + 1);
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

void solve() {
    int n, m;
    cin >> n >> m;
    lng a_sum = 0;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
        a_sum += a;
    }
    lng b_sum = 0;
    vector<int> B(n);
    for (int &b : B) {
        cin >> b;
        b_sum += b;
    }
    int N = 2 * n + 1;
    vector<vector<int>> adjl(N + 1);
    vector<vector<lng>> cap(N + 1, vector<lng>(N + 1));
    for (int i = 1; i <= n; i++) {
        adjl[0].pb(i);
        adjl[i].pb(i + n);
        cap[0][i] = A[i - 1];
        cap[i][i + n] = INF64;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjl[u].pb(v + n);
        adjl[v].pb(u + n);
        cap[u][v + n] = INF64;
        cap[v][u + n] = INF64;
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        adjl[i].pb(N);
        cap[i][N] = B[i - n - 1];
    }

    EdmondsKarp ek(N, adjl, cap);

    lng mf = ek.getMaxFlow(0, N);
    if (mf != a_sum || mf != b_sum) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= 2 * n; j++) {
            cout << ek.ncap[j][i] << ' ';
        }
        cout << endl;
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