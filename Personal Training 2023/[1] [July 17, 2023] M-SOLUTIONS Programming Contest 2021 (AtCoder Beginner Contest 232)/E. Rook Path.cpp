// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define TROUBLESHOOT

int const MOD = 998244353;

lng fast_mod_pow(lng a, int b) {
    if (b == 0) {
        return 1;
    }

    a %= MOD;
    
    if (a == 0) {
        return 0;
    }

    lng res = fast_mod_pow(a, b / 2);
    (res *= res) %= MOD;
    if (b % 2 == 1) {
        (res *= a) %= MOD;
    }

    return res;
}

void solve() {
    int h, w, k;
    cin >> h >> w >> k;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    // origin, h-linear, v-linear, non-linear
    vector<vector<lng>> dp(k + 1, vector<lng>(4));
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        (dp[i][0] = dp[i - 1][1] + dp[i - 1][2]) %= MOD;
        (dp[i][1] = dp[i - 1][0] * (w - 1) + dp[i - 1][1] * (w - 2) + dp[i - 1][3]) %= MOD;
        (dp[i][2] = dp[i - 1][0] * (h - 1) + dp[i - 1][2] * (h - 2) + dp[i - 1][3]) %= MOD;
        (dp[i][3] = dp[i - 1][1] * (h - 1) + dp[i - 1][2] * (w - 1) + dp[i - 1][3] * (w + h - 4)) %= MOD;
    
        /*
        if (i <= 10) {
            cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << ' ' << dp[i][3] << endl;
        }
        //*/
    }

    if (x1 == x2 && y1 == y2) {
        cout << dp[k][0] << endl;
    } else if (x1 == x2) {
        cout << dp[k][1] * fast_mod_pow(w - 1, MOD - 2) % MOD << endl;
    } else if (y1 == y2) {
        cout << dp[k][2] * fast_mod_pow(h - 1, MOD - 2) % MOD << endl;
    } else {
        cout << dp[k][3] * fast_mod_pow(1ll * h * w - w - h + 1, MOD - 2) % MOD << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef TROUBLESHOOT
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef TROUBLESHOOT
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef TROUBLESHOOT
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}