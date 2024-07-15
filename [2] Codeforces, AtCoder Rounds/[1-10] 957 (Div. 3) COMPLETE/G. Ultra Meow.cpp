// 人外有人，天外有天
// author: Ausp3x

// #pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
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

int MOD = 1000000007;

lng modPow(lng x, int y) {
    lng res = 1;
    while (y > 0) {
        if (y & 1) {
            res *= x;
            res %= MOD;
        }

        y >>= 1;
        x *= x;
        x %= MOD;
    }

    return (res + MOD) % MOD;
}

int N = 5000;
vector<lng> fac(N + 1);
vector<lng> inv_fac(N + 1);

lng choose(int n, int k) {
    if (k > n)
        return 0;
    
    return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD; 
}

void solve(int t) {
    int n;
    cin >> n;

    lng ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i + 1; j >= i + 1; j--) {
            int a = min(j - 1, n), b = max(n - j, 0);
            // cout << i << ' ' << j << ' ' << a << ' ' << b << endl;
            ans += j * choose(a, i - (2 * i + 1 - j)) % MOD * choose(b, (2 * i + 1 - j)) % MOD;
            ans %= MOD;
        }
    }

    cout << ans << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i <= N; i++)
        fac[i] = fac[i - 1] * i % MOD;
    
    for (int i = 0; i <= N; i++)
        inv_fac[i] = modPow(fac[i], MOD - 2);

    // cout << choose(0, 0) << endl;
    // cout << choose(6, 0) << endl;
    // cout << choose(6, 1) << endl;
    // cout << choose(6, 2) << endl;
    // cout << choose(6, 3) << endl;
    // cout << choose(6, 4) << endl;
    // cout << choose(6, 5) << endl;
    // cout << choose(6, 6) << endl;
    // cout << endl;

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}