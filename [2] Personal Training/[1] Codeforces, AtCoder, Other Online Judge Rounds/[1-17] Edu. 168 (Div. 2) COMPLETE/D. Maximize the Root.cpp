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
vector<lng> A;
vector<vector<int>> adjl;

vector<bool> vst;

void bfs(int u) {
    vst[u] = true;
    
    lng a_vmin = INF64;
    for (int v : adjl[u]) {
        if (vst[v])
            continue;
        
        bfs(v);
        a_vmin = min(a_vmin, A[v]);
    }

    if (a_vmin == INF64)
        return;
    
    if (u == 0) {
        A[u] += a_vmin;
        return;
    }

    if (A[u] >= a_vmin) {
        A[u] = a_vmin;
        return;
    }

    A[u] += (a_vmin - A[u]) / 2;

    return;
}


void solve() {
    cin >> n;
    A.clear();
    A.resize(n);
    for (lng &a : A)
        cin >> a;
    adjl.clear();
    adjl.resize(n);
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        u--;

        adjl[u].pb(i);
        adjl[i].pb(u);
    }

    vst.clear();
    vst.resize(n);
    bfs(0);

    // for (int x : A)
    //     cout << x << ' ';
    // cout << endl;

    cout << A[0] << endl;

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