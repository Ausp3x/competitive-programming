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
    int size = 1;
};

int ans;
vector<node> memo;
vector<vector<int>> adjl;
void dfs(int cur) {
    memo[cur].vst = true;
    for (int nxt : adjl[cur]) {
        if (memo[nxt].vst)
            continue;

        dfs(nxt);
        memo[cur].size += memo[nxt].size;
    }

    if (memo[cur].size % 2 == 0) {
        ans++;
        memo[cur].size = 0;
    }

    return;
}

void solve(int t) {
    int n;
    cin >> n;
    adjl.clear();
    adjl.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        
        adjl[u].pb(v);
        adjl[v].pb(u);
    }

    if (n % 2 == 1) {
        cout << -1 << endl;
        return;
    }

    int root = -1;
    for (int i = 1; i <= n; i++)
        if (adjl[i].size() == 1) {
            root = i;
            break;
        }

    // cout << root << endl;

    ans = 0;
    memo.resize(n + 1);
    dfs(root);

    cout << ans - 1 << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}