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

int n;
vector<vector<int>> adjl;

vector<int> sze;
void getSizes(int cur) {
    for (int nxt : adjl[cur]) {
        getSizes(nxt);
        sze[cur] += sze[nxt];
    }

    return;
}

void solve() {
    int q;
    cin >> n >> q;
    vector<int> par(n + 1, 0);
    adjl.clear();
    adjl.resize(n + 1);
    adjl[0].pb(1);
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;

        par[i] = a;
        adjl[a].pb(i);
    }

    sze.clear();
    sze.resize(n + 1, 1);
    getSizes(0);
    
    // for (int x : sze) 
    //     cout << x << ' ';
    // cout << endl;

    vector<int> con(n + 1);
    for (int i = 1; i <= n; i++)
        con[i] = sze[par[i]] - sze[i];

    // for (int x : con)
    //     cout << x << ' ';
    // cout << endl;

    vector<int> P(n + 1), idxs(n + 1);
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;

        P[i] = p;
        idxs[p] = i;
    }

    int ok_cnt = 0;
    vector<bool> ok(n + 1);
    ok[0] = true;
    for (int i = 1; i <= n; i++) {
        if (0 < idxs[i] - idxs[par[i]] && idxs[i] - idxs[par[i]] <= con[i]) {
            ok_cnt++;
            ok[i] = true;
        }
    }

    while (q--) {
        int i, j;
        cin >> i >> j;
    
        swap(P[i], P[j]);
        idxs[P[i]] = i;
        idxs[P[j]] = j;

        // for (int x : P)
        //     cout << x << ' ';
        // cout << endl;

        // for (int x : idxs)
        //     cout << x << ' ';
        // cout << endl;

        int x = P[i], y = P[j];

        bool chk = 0 < idxs[x] - idxs[par[x]] && idxs[x] - idxs[par[x]] <= con[x];
        ok_cnt += chk - ok[x];
        ok[x] = chk;

        chk = 0 < idxs[y] - idxs[par[y]] && idxs[y] - idxs[par[y]] <= con[y];
        ok_cnt += chk - ok[y];
        ok[y] = chk;

        for (int nx : adjl[x]) {
            chk = 0 < idxs[nx] - idxs[x] && idxs[nx] - idxs[x] <= con[nx];
            ok_cnt += chk - ok[nx];
            ok[nx] = chk;
        }

        for (int ny : adjl[y]) {
            chk = 0 < idxs[ny] - idxs[y] && idxs[ny] - idxs[y] <= con[ny];
            ok_cnt += chk - ok[ny];
            ok[ny] = chk;
        }

        cout << (ok_cnt == n ? "YES" : "NO") << endl;
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