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

struct node {
    bool vst = false;
    lng d_from_1 = -1;
    lng d_from_end1 = -1;
    lng d_from_end2 = -1;
};

void solve(int t) {
    int n, k, c;
    cin >> n >> k >> c;
    vector<vector<int>> adjl(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adjl[u].pb(v);
        adjl[v].pb(u);
    }
    
    int end1 = -1, max_dis = -1;
    stack<pair<int, int>> dfs;
    vector<node> dp(n + 1);
    dfs.push({1, 0}); 
    while (!dfs.empty()) {
        auto [cur, d] = dfs.top();
        dfs.pop();
        
        dp[cur].vst = true;
        dp[cur].d_from_1 = d;
        if (d > max_dis) {
            end1 = cur;
            max_dis = d;
        }

        for (int nxt : adjl[cur]) {
            if (dp[nxt].vst)
                continue;
            
            dfs.push({nxt, d + 1});
        }
    }

    int end2 = -1;
    max_dis = -1;
    dfs.push({end1, 0});
    for (int i = 0; i <= n; i++)
        dp[i].vst = false;
    while (!dfs.empty()) {
        auto [cur, d] = dfs.top();
        dfs.pop();
        
        dp[cur].vst = true;
        dp[cur].d_from_end1 = d;
        if (d > max_dis) {
            end2 = cur;
            max_dis = d;
        }

        for (int nxt : adjl[cur]) {
            if (dp[nxt].vst)
                continue;
            
            dfs.push({nxt, d + 1});
        }
    }

    // cout << end1 << ' ' << end2 << endl;

    dfs.push({end2, 0});
    for (int i = 0; i <= n; i++)
        dp[i].vst = false;
    while (!dfs.empty()) {
        auto [cur, d] = dfs.top();
        dfs.pop();
        
        dp[cur].vst = true;
        dp[cur].d_from_end2 = d;

        for (int nxt : adjl[cur]) {
            if (dp[nxt].vst)
                continue;
            
            dfs.push({nxt, d + 1});
        }
    }

    // for (int i = 1; i <= n; i++)
    //     cout << dp[i].d_from_1 << ' ' << dp[i].d_from_end1 << ' ' << dp[i].d_from_end2 << endl;
    // cout << endl;

    lng ans = -INF64;
    for (int i = 1; i <= n; i++)
        ans = max(ans, k * max(dp[i].d_from_end1, dp[i].d_from_end2) - c * dp[i].d_from_1);

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}