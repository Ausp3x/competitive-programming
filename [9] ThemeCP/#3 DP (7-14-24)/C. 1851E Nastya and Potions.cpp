// 人外有人，天外有天
// author: Ausp3x

// #pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
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

void solve(int t) {
    int n, k;
    cin >> n >> k;
    vector<lng> C(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> C[i];
    queue<int> q;
    vector<lng> MC(n + 1, INF64);
    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        q.push(p);
        MC[p] = 0;
    }
    vector<int> cnt(n + 1);
    vector<vector<int>> adjl(n + 1);
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;

        if (m == 0 && MC[i] != 0) {
            q.push(i);
            continue;
        }

        if (MC[i] != 0)
            cnt[i] = m;
        for (int j = 0; j < m; j++) {
            int e;
            cin >> e;
            if (MC[i] != 0)
                adjl[e].pb(i);
        }            
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (int j : adjl[i])
    //         cout << j << ' ';
    //     cout << endl;
    // }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // cout << cur << ' ' << endl;

        MC[cur] = min(MC[cur], C[cur]);
        for (int nxt : adjl[cur]) {
            if (MC[nxt] == INF64)
                MC[nxt] = MC[cur];
            else
                MC[nxt] += MC[cur]; 
            cnt[nxt]--;
            if (cnt[nxt] == 0)
                q.push(nxt);            
        }
    }

    for (int i = 1; i <= n; i++)
        cout << MC[i] << ' ';
    cout << endl;

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