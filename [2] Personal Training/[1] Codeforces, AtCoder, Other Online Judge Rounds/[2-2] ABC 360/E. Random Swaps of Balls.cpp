// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int MOD = 998244353;

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
    lng N;
    int K;
    cin >> N >> K;

    if (N == 2) {
        cout << 499122178 << endl;
        return;
    }

    lng N_inv = modPow(N, MOD - 2);
    lng p_same = ((N - 1) * (N - 1) + 1) % MOD * N_inv % MOD * N_inv % MOD;
    lng p_diff = 2 * N_inv * N_inv % MOD;

    // cout << N_inv << ' ' << p_same << ' ' << p_diff << endl;

    vector<vector<lng>> ans(2, vector<lng>(2));
    ans[0][0] = 1;
    for (int i = 1; i <= K; i++) {
        int cur = i & 1, prv = !cur;
        ans[cur][0] = (ans[prv][0] * p_same % MOD                              + (N - 1) * ans[prv][1] % MOD * p_diff % MOD) % MOD;
        ans[cur][1] = (ans[prv][0] * p_diff % MOD + ans[prv][1] * p_same % MOD + (N - 2) * ans[prv][1] % MOD * p_diff % MOD) % MOD;
    }

    lng ANS = 0;
    ANS += ans[K & 1][0];
    ANS += ans[K & 1][1] * (N * (N + 1) % MOD * modPow(2, MOD - 2) % MOD - 1 + MOD) % MOD;

    cout << ANS % MOD << endl; 

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