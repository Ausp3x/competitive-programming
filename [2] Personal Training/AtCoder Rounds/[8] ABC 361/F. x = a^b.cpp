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

void solve(int t) {
    lng n;
    cin >> n;

    __int128 N = n;
    set<__int128> powers;
    powers.insert(1);

    if (n <= 1e12) {
        for (__int128 a = 2; a * a <= N; a++) {
            __int128 cur = a;
            for (int b = 2; cur * a <= N; b++) {
                cur *= a;
                powers.insert(cur);
            }
        }

        cout << powers.size() << endl;
        return;
    }
    
    for (__int128 a = 2; a * a * a <= N; a++) {
        __int128 cur = a;
        for (int b = 2; cur * a <= N; b++) {
            cur *= a;
            powers.insert(cur);
        }
    }

    // for (lng x : powers)
    //     cout << x << ' ';
    // cout << endl;

    lng sq_max = sqrt(n);
    lng cb_max = cbrt(n);
    lng ans = powers.size() + sq_max - cb_max;
    for (lng x : powers)
        if (cb_max < x && x <= sq_max)
            ans--;

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}