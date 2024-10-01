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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m;
    cin >> n >> m;
    vector<lng> V(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        
        lng r = rng();
        V[a] ^= r;
        V[b] ^= r;
    }

    lng cur = 0, minus = 0;
    map<lng, lng> cnts;
    for (lng v : V) {
        cur ^= v;
        minus = max(minus, ++cnts[cur]);
    }

    cout << n - minus << endl;

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