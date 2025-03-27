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
    int n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << 0 << endl;
        return;
    }

    if (k <= n) {
        cout << 1 << endl;
        return;
    }

    k -= n;

    int cnt = 1, cur = n - 1; 
    while (k > 0 && cur > 0) {
        if (k > 0)
            cnt++;
        k -= min(cur, k);

        // cout << cnt << ' ' << k << ' ' << cur << endl;

        if (k > 0)
            cnt++;
        k -= min(cur, k);

        // cout << cnt << ' ' << k << ' ' << cur << endl;

        cur--;
    }

    cout << cnt << endl;
    
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