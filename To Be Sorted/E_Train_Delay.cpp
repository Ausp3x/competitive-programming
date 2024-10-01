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

void solve() {
    int N, M, x1;
    cin >> N >> M >> x1;
    vector<vector<tuple<int, int, int>>> in(N), out(M);
    // bgn, end, bgn_t, end_t
    map<vector<int>, int> edg_idxs;
    for (int i = 0; i <= M; i++) {
        int a, b, s, t;
        cin >> a >> b >> s >> t;
        in[b].pb({t, a, i});
        out[a].pb({s, b, i});
    }

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