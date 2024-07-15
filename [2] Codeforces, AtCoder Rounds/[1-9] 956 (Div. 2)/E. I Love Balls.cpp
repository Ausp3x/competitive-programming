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

int const MOD = 1000000007;

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

lng modInv(lng x) {
    return modPow(x, MOD - 2);
}

void solve(int t) {
    int n, k;
    cin >> n >> k;
    lng k_sum = 0, n_sum = 0;
    vector<int> V(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
        if (i < k)
            (k_sum += V[i]) %= MOD;
        else
            (n_sum += V[i]) %= MOD;
    }

    if (k == n) {
        cout << k_sum + n_sum << ' ' << 0 << endl;
        return;
    }

    lng kE = k_sum * modInv(k) % MOD;
    n -= k;
    lng nE = n_sum * modInv(n) % MOD;
    
    cout << ((n / 2 + 1) * modInv(n + 1) % MOD * k % MOD * kE % MOD + ((n + 1) / 2) * nE % MOD) % MOD << ' ';
    cout << (((n + 1) / 2) * modInv(n + 1) % MOD * k % MOD * kE % MOD + (n / 2) * nE % MOD) % MOD << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}