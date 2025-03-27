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

void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, int> edge_idx;
    vector<set<int>> adjl(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;

        edge_idx[{u, v}] = i;
        edge_idx[{v, u}] = i;
        adjl[u].insert(v);
        adjl[v].insert(u);
    }

    vector<int> par(n + 1);
    par[1] = 1;        
    function<void(int)> dfs = [&](int cur) {
        for (int nxt : adjl[cur]) {
            if (nxt == par[cur])
                continue;

            par[nxt] = cur;
            dfs(nxt);
        }

        return;
    };

    dfs(1);

    queue<int> light;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j : adjl[i]) {
            if (j == par[i])
                continue;
            
            if (adjl[j].size() == 1)
                cnt++;
        }

        if (cnt == adjl[i].size() - (i != 1) && cnt > 0) 
            light.push(i);
    }

    vector<bool> vst(n + 1);
    vector<int> ans;
    while (!light.empty()) {
        int cur = light.front();
        light.pop();

        if (vst[cur])
            continue;

        int prv = par[cur];
        if (prv == cur) {
            if (adjl[cur].size() != 2) {
                cout << -1 << endl;
                return;
            }

            int nxt1 = *adjl[cur].begin();
            int nxt2 = *adjl[cur].rbegin();
            adjl[cur].erase(nxt1);
            adjl[cur].erase(nxt2);
            adjl[nxt1].erase(cur);
            adjl[nxt2].erase(cur);
            par[nxt1] = nxt1;
            par[nxt2] = nxt2;
            vst[cur] = vst[nxt1] = vst[nxt2] = true;
            continue;
        }
        
        adjl[prv].erase(cur);
        adjl[cur].erase(prv);
        par[cur] = cur;
        if (adjl[cur].size() > 2) {
            cout << -1 << endl;
            return;
        }

        if (adjl[cur].size() == 2) {
            int nxt1 = *adjl[cur].begin();
            int nxt2 = *adjl[cur].rbegin();
            adjl[cur].erase(nxt1);
            adjl[cur].erase(nxt2);
            adjl[nxt1].erase(cur);
            adjl[nxt2].erase(cur);
            par[nxt1] = nxt1;
            par[nxt2] = nxt2;
            vst[cur] = vst[nxt1] = vst[nxt2] = true;
            ans.pb(edge_idx[{prv, cur}]);
            // cout << "1: " << prv << ' ' << cur << ' ' << edge_idx[{prv, cur}] << endl;
            
            if (true) {
                int cnt = 0;
                for (int u : adjl[prv]) {
                    if (u == par[prv])
                        continue;
                    
                    if (adjl[u].size() == 1)
                        cnt++;
                }

                if (cnt == adjl[prv].size() - (par[prv] != prv) && cnt > 0)
                    light.push(prv);
            }

            int ppv = par[prv];
            if (ppv != prv) {
                int cnt = 0;
                for (int u : adjl[ppv]) {
                    if (u == par[ppv])
                        continue;
                    
                    if (adjl[u].size() == 1)
                        cnt++;
                }

                if (cnt == adjl[ppv].size() - (par[ppv] != ppv) && cnt > 0)
                    light.push(ppv);
            }
            continue;
        }

        int ppv = par[prv];
        int nxt = *adjl[cur].begin();
        adjl[ppv].erase(prv);
        adjl[prv].erase(ppv);
        adjl[cur].erase(nxt);
        adjl[nxt].erase(cur);
        par[prv] = prv;
        par[nxt] = nxt;
        vst[prv] = vst[cur] = vst[nxt] = true;
        if (ppv != prv)
            ans.pb(edge_idx[{ppv, prv}]);
        // cout << "2: " <<  ppv << ' ' << prv << ' ' << edge_idx[{ppv, prv}] << endl;
    
        vector<int> rem;
        for (int u : adjl[prv]) 
            rem.pb(u);
        for (int u : rem) {
            adjl[prv].erase(u);
            adjl[u].erase(prv);
            par[u] = u;
            ans.pb(edge_idx[{prv, u}]);
            // cout << "3: " << prv << ' ' << u << ' ' << edge_idx[{prv, u}] << endl;
        }

        if (true) {
            int cnt = 0;
            for (int u : adjl[ppv]) {
                if (u == par[ppv])
                    continue;
                
                if (adjl[u].size() == 1)
                    cnt++;
            }

            if (cnt == adjl[ppv].size() - (par[ppv] != ppv) && cnt > 0)
                light.push(ppv);
        }

        int ppp = par[ppv];
        if (ppp != ppv) {
            int cnt = 0;
            for (int u : adjl[ppp]) {
                if (u == par[ppp])
                    continue;
                
                if (adjl[u].size() == 1)
                    cnt++;
            }

            if (cnt == adjl[ppp].size() - (par[ppp] != ppp) && cnt > 0)
                light.push(ppp);
        }
    }

    int sum = accumulate(vst.begin(), vst.end(), 0);
    if (sum < n) {
        cout << -1 << endl;
        return;
    }

    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << ' ';
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        // cout << endl;
    }

    return 0;
}