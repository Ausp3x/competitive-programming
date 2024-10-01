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
    int N;
    cin >> N;
    vector<pair<int, int>> LR(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> LR[i].fi >> LR[i].se;

    vector<pair<int, int>> openings(N + 1);
    for (int i = 2; i <= N; i++) {
        openings[i].fi = max(LR[i].fi, LR[i - 1].fi);
        openings[i].se = max(LR[i].se, LR[i - 1].se);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
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