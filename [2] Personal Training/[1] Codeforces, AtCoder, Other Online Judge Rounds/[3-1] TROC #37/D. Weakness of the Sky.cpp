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

int const MOD = 998244353;

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

void solve() {
    int N;
    cin >> N;
    vector<lng> A(2 * N + 1);
    for (int i = 1; i <= 2 * N; i++)
        cin >> A[i];
    
    vector<lng> T(2 * N + 1), W(2 * N + 1);
    for (int i = 1; i <= 2 * N; i++) {
        T[i] = max(i - N + 1, 1);
        W[i] = min(2 * N - i + 1, N);
    }

    // for (lng x : T)
    //     cout << x << ' ';
    // cout << endl;
    // for (lng x : W)
    //     cout << x << ' ';
    // cout << endl;

    vector<lng> W_prf(2 * N + 1, 1);
    for (int i = 1; i <= 2 * N; i++) { 
        W_prf[i] = W[i] * W_prf[i - 1];
        W_prf[i] %= MOD;
    }

    // for (lng x : W_prf)
    //     cout << x << ' ';
    // cout << endl;

    vector<lng> Wm1_prf(2 * N + 1, 1);
    for (int i = 1; i <= 2 * N; i++) {
        Wm1_prf[i] = (W[i] - 1) * Wm1_prf[i - 1];
        Wm1_prf[i] %= MOD;
    }
    
    // for (lng x : Wm1_prf)
    //     cout << x << ' ';
    // cout << endl;

    // lng ans = 0;
    // for (int i = 1; i <= 2 * N; i++)
    //     for (int j = T[i]; j <= 2 * N; j++) {
    //         ans += (2 * N - j + 1) * A[i] % MOD 
    //                * W_prf[T[i] - 1] % MOD 
    //                * Wm1_prf[j - 1] % MOD * modPow(Wm1_prf[T[i] - 1], MOD - 2) % MOD 
    //                * W_prf[2 * N] % MOD * modPow(W_prf[j], MOD - 2) % MOD;
    //         ans %= MOD;
    //     }

    lng ans = 0, cur = accumulate(A.begin() + 1, A.begin() + N + 1, 0ll) % MOD;
    ans = (2 * N) * cur % MOD * W_prf[2 * N] % MOD * modPow(W_prf[1], MOD - 2) % MOD;
    for (int j = 1; j < 2 * N; j++) {
        cur *= Wm1_prf[j] % MOD * modPow(Wm1_prf[j - 1], MOD - 2) % MOD;
        cur %= MOD;
        if (N + j <= 2 * N) {
            cur += A[N + j] * W_prf[j] % MOD;
            cur %= MOD;
        }

        ans += (2 * N - j) * cur % MOD * W_prf[2 * N] % MOD * modPow(W_prf[j + 1], MOD - 2) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

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