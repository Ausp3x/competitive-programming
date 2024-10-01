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
    int l, r;
    cin >> l >> r;

    int ll = l;
    lng ans = 0;
    while (ll > 0) {
        ll /= 3;
        ans += 2;
    }

    if (l == r) {
        cout << ans << endl;
        return;
    }

    // cout << ans << ' ';

    int val = 1;
    for (int i = 0; i < 13; i++) {
        ans += 1ll * max(r - val + 1, 0);
        ans -= 1ll * max(l - val + 1, 0);
        val *= 3;
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