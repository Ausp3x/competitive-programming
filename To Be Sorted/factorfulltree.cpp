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

int n;
vector<vector<int>> adjl;
vector<int> primes = {
      2,   3,   5,   7,  11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
     73,  79,  83,  89,  97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
    179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281
};

vector<int> par, heights;
map<int, vector<int>> depth_to_nodes;
void initDfs(int cur, int prv, int d) {
    par[cur] = prv;
    depth_to_nodes[d].pb(cur);

    for (int nxt : adjl[cur]) {
        if (nxt == prv)
            continue;

        initDfs(nxt, cur, d + 1);
        heights[cur] = max(heights[cur], heights[nxt] + 1);
    }

    return;
}

int j = 0;
vector<bool> vst;
vector<lng> ans;
void dfs(int cur) {
    vst[cur] = true;
    ans[cur] = primes[j];

    priority_queue<pair<int, int>> pq;
    for (int nxt : adjl[cur]) {
        if (nxt == par[cur])
            continue;

        pq.push({heights[nxt], nxt});
    }

    if (!pq.empty()) 
        dfs(pq.top().se);

    return;
}

void solve() {
    cin >> n;
    adjl.clear();
    adjl.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adjl[u].pb(v);
        adjl[v].pb(u);
    }

    par.clear();
    par.resize(n + 1);
    heights.clear();
    heights.resize(n + 1, 1);
    initDfs(1, 1, 1);

    j = 0;
    vst.clear();
    vst.resize(n + 1);
    ans.clear();
    ans.resize(n + 1);
    vst[1] = true;
    ans[1] = 1;
    // h, node
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++)
        pq.push({heights[i], i});
    while (!pq.empty()) {
        auto [h, cur] = pq.top();
        pq.pop();

        if (vst[cur])
            continue;

        // cout << cur << ' ' << primes[j] << endl;

        dfs(cur);
        
        j++;
    }
    
    for (int i = 1; i <= n; i++) 
        for (int cur : depth_to_nodes[i])
            ans[cur] *= ans[par[cur]];

    for (int i = 1; i <= n; i++) 
        cout << ans[i] << ' ';
    cout << endl;

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