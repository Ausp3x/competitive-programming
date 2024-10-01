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
    lng n, m;
    cin >> n >> m;
    vector<pair<lng, lng>> AC(n);
    for (int i = 0; i < n; i++)
        cin >> AC[i].fi;
    for (int i = 0; i < n; i++)
        cin >> AC[i].se;

    sort(AC.begin(), AC.end());
    
    // for (auto [x, y] : AC)
    //     cout << x << ' ' << y << endl;

    lng ans = 0;
    for (int i = 0; i < n; i++) 
        ans = max(ans, AC[i].fi * min(m / AC[i].fi, AC[i].se));
    
    for (int i = 0; i + 1 < n; i++) {
        if (AC[i].fi + 1 != AC[i + 1].fi) 
            continue;

        if (AC[i].fi * AC[i].se <= m) {
            lng cur = AC[i].fi * AC[i].se;

            lng a = AC[i + 1].se - min((m - cur) / AC[i + 1].fi, AC[i + 1].se);
            cur += AC[i + 1].fi * min((m - cur) / AC[i + 1].fi, AC[i + 1].se);

            cur += min({m - cur, AC[i].se, a});

            ans = max(ans, cur);
            continue;
        }

        lng a = min(m / AC[i].fi, AC[i].se);
        lng cur = AC[i].fi * min(m / AC[i].fi, AC[i].se);
    
        cur += min({m - cur, a, AC[i + 1].se});

        ans = max(ans, cur);
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