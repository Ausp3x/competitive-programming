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

int N = 300000;
vector<lng> fac(N + 1);
vector<lng> inv_fac(N + 1);

lng choose(int n, int k) {
    if (k > n)
        return 0;
    
    return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD; 
}

void solve(int t) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;

        if (r == c)
            n--;
        else
            n -= 2;
    }

    // cout << n << ' ';

    lng ans = 1, cur = 2;
    for (int i = n - 2; i >= 0; i -= 2) {
        ans += choose(n, i) * cur;
        ans %= MOD;

        cur *= 2 * (n - i + 1);
        cur %= MOD;
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

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}