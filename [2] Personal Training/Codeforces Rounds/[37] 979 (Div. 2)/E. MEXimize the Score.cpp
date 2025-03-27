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
typedef __int128     lll;
template<class T> 
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int const MOD = 998'244'353;

struct ModFac {
    int n, MOD;
    vector<lng> fac, inv_fac;

    ModFac(int n, int MOD): n(n), MOD(MOD) {
        fac.resize(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i;
            fac[i] %= MOD;
        }

        inv_fac.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            inv_fac[i] = modPow(fac[i], MOD - 2);
        }
    }

    lng modPow(lng x, lng y) {
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

    lng combi(int x, int y) {
        if (y > x || y < 0)
            return 0;

        return fac[x] * inv_fac[y] % MOD * inv_fac[x - y] % MOD; 
    }

    lng permu(int x, int y) {
        if (y > x || y < 0)
            return 0;
            
        return fac[x] * inv_fac[x - y] % MOD;
    }
};

ModFac mf(200'000, MOD);

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    vector<int> F(n);
    for (int a : A)
        F[a]++;

    vector<lng> ps, co;
    vector<vector<lng>> dp(n, vector<lng>(1));
    for (int j = 1; j <= F[0]; j++) 
        dp[0].pb(mf.combi(F[0], j));
    for (int i = 1; i < n; i++) {
        ps.clear();
        ps.resize(1);
        for (lng v : dp[i - 1])
            ps.pb((ps.back() + v) % MOD);

        co.clear();
        co.resize(1);
        for (int j = 0; j <= F[i]; j++)
            co.pb((co.back() + mf.combi(F[i], j)) % MOD);

        int m = ps.size() - 1;
        dp[i].resize(min(m, F[i] + 1));
        for (int j = 1; j < dp[i].size(); j++) {
            dp[i][j] = mf.combi(F[i], j) * (ps[m] - ps[j] + MOD) % MOD + (co.back() - co[j + 1] + MOD) % MOD * dp[i - 1][j] % MOD;
            dp[i][j] %= MOD;
        }
    }

    int i = 0;
    lng ans = 0;
    for (auto V : dp) {
        n -= F[i++];
        for (int j = 1; j < V.size(); j++) {
            ans += j * V[j] % MOD * mf.modPow(2, n) % MOD;
            ans %= MOD;
        }
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