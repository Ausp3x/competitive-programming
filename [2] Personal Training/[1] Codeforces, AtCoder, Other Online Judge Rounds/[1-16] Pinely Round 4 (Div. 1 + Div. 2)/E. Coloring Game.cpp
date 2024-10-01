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

int n, m;
vector<vector<int>> adjl(n + 1);
vector<queue<int>> grps(3);

bool isTwoColorable() {
    queue<pair<int, int>> q;
    vector<int> clr(n + 1);
    q.push({1, 1});
    clr[1] = 1;
    while (!q.empty()) {
        auto [cur, cur_clr] = q.front();
        q.pop();

        int nxt_clr = 3 - cur_clr;
        for (int nxt : adjl[cur]) {
            if (clr[nxt] == 0) {
                q.push({nxt, nxt_clr});
                clr[nxt] = nxt_clr;
                continue;
            }

            if (clr[nxt] != nxt_clr)
                return false;
        } 
    }

    for (int i = 1; i <= n; i++)
        grps[clr[i]].push(i);
    return true;
}

void solve() {
    cin >> n >> m;
    adjl.clear();
    adjl.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjl[u].pb(v);
        adjl[v].pb(u);
    }

    if (!isTwoColorable()) {
        cout << "Alice" << endl;
        for (int i = 0; i < n; i++) {
            cout << 1 << ' ' << 2 << endl;
            
            int u, c;
            cin >> u >> c;
        }

        return;
    }

    cout << "Bob" << endl;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }

        if (a == 1 && b == 2) {
            if (!grps[1].empty()) {
                cout << grps[1].front() << ' ' << 1 << endl;
                grps[1].pop();
            } else {
                cout << grps[2].front() << ' ' << 2 << endl;
                grps[2].pop();
            }
            continue;
        } 

        // b == 3
        if (!grps[a].empty()) {
            cout << grps[a].front() << ' ' << a << endl;
            grps[a].pop();
        } else {
            cout << grps[3 - a].front() << ' ' << 3 << endl;
            grps[3 - a].pop();
        }
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