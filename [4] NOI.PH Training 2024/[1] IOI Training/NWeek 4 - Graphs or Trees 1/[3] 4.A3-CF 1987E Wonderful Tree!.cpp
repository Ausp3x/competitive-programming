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

void solve() {
    int n;
    cin >> n;
    vector<lng> A(n);
    for (lng &a : A)
        cin >> a;
    vector<vector<int>> adjl(n);
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        u--;

        adjl[u].pb(i);
        adjl[i].pb(u);
    }

    vector<int> depth(n, 0);
    vector<lng> B = A;
    for (int i = 0; i < n; i++)
        if (adjl[i].size() <= 1 && i != 0) 
            B[i] = INF64;
        else
            B[i] = -B[i];

    queue<pair<int, int>> q;
    vector<bool> vst(n);
    q.push({0, 0});
    while (!q.empty()) {
        auto [cur, d] = q.front();
        q.pop();

        if (vst[cur])
            continue;
        vst[cur] = true;

        depth[cur] = d;
        for (int nxt : adjl[cur]) {
            if (vst[nxt])
                continue;

            q.push({nxt, d + 1});
            B[cur] += A[nxt];
        }
    }

    // for (int x : depth)
    //     cout << x << ' ';
    // cout << endl;
    // for (int x : B)
    //     cout << x << ' ';
    // cout << endl;

    int max_depth = 0;
    for (int i = 0; i < n; i++)
        max_depth = max(max_depth, depth[i]);

    // cout << max_depth << endl;

    vector<vector<int>> nodes_by_depth(max_depth + 1);
    for (int i = 0; i < n; i++)
        nodes_by_depth[depth[i]].pb(i);

    lng ans = 0;
    for (int i = max_depth - 1; i >= 0; i--)
        for (int j : nodes_by_depth[i]) {
            if (B[j] >= 0)
                continue;
            
            queue<int> qq;
            vector<vector<int>> cur_nodes_by_depth(max_depth + 1);
            qq.push(j);
            while (!qq.empty()) {
                int cur = qq.front();
                qq.pop();

                cur_nodes_by_depth[depth[cur]].pb(cur);

                for (int nxt : adjl[cur]) {
                    if (depth[nxt] < depth[cur])
                        continue;
                    
                    qq.push(nxt);
                }
            }
            
            for (int i2 = i + 1; i2 <= max_depth; i2++)
                for (int j2 : cur_nodes_by_depth[i2]) {
                    if (B[j2] <= 0)
                        continue;
                    
                    if (B[j2] == INF64) {
                        ans += 1ll * (i2 - i) * abs(B[j]);
                        B[j] = 0;
                        continue;
                    }

                    lng cur = min(abs(B[j]), B[j2]);
                    ans += 1ll * (i2 - i) * cur;
                    B[j] += cur;
                    B[j2] -= cur;
                }
        }

    cout << ans << endl;

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