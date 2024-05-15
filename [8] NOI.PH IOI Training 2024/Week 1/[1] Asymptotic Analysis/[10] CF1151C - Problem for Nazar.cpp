// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int const MOD = 1000000007;

void solve() {
    lng l, r;
    cin >> l >> r;

    lng l2 = l - 1, l_h1b = 63 - __builtin_clzll(l2);
    lng l_oc = 0, l_ec = 0;
    if (l > 1) {    
        for (int i = 0; i < l_h1b; i++) {
            if (i % 2 == 0) {
                l_oc += 1ll << i;
            } else {
                l_ec += 1ll << i;
            }
        }
        if (l2 == 1) {
            l_oc = 1;
        } else {
            if (l_h1b % 2 == 0) {
                l_oc += l2 - ((1ll << l_h1b) - 1);
            } else {
                l_ec += l2 - ((1ll << l_h1b) - 1);
            }
        }
    }

    lng r_h1b = 63 - __builtin_clzll(r);
    lng r_oc = 0, r_ec = 0;
    for (int i = 0; i < r_h1b; i++) {
        if (i % 2 == 0) {
            r_oc += 1ll << i;
        } else {
            r_ec += 1ll << i;
        }
    }
    if (r == 1) {
        r_oc = 1;
    } else {
        if (r_h1b % 2 == 0) {
            r_oc += r - ((1ll << r_h1b) - 1);
        } else {
            r_ec += r - ((1ll << r_h1b) - 1);
        }
    }

    // cout << l_oc << endl << l_ec << endl << r_oc << endl << r_ec << endl;
    
    lng ans = ((r_oc % MOD) * (r_oc % MOD) % MOD + (r_ec % MOD) * ((r_ec + 1) % MOD) % MOD) % MOD;
    ans -= ((l_oc % MOD) * (l_oc % MOD) % MOD + (l_ec % MOD) * ((l_ec + 1) % MOD) % MOD) % MOD;
    
    cout << (ans + MOD) % MOD << endl;

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