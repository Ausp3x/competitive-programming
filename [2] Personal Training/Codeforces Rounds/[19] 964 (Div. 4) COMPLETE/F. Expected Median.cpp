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

    lng combi(int x, int y) {
        if (y > x)
            return 0;

        return fac[x] * inv_fac[y] % MOD * inv_fac[x - y] % MOD; 
    }

    lng permu(int x, int y) {
        if (y > x)
            return 0;
            
        return fac[x] * inv_fac[x - y] % MOD;
    }

    void debugPrint() {
        cout << n << endl;
        cout << "fac: " << endl;
        for (bool x : fac) {
            cout << x << ' ';
        }
        cout << endl;
        cout << "inv_fac: " << endl;
        for (lng x : inv_fac) {
            cout << x << ' ';
        }
        cout << endl;

        return;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    vector<int> cnts(2);
    for (int &a : A) {
        cin >> a;
        cnts[a]++;
    }
    
    // cout << cnts[0] << ' ' << cnts[1] << endl;

    lng ans = 0;
    ModFac mf(n, MOD);
    for (int i = (k + 1) / 2; i <= k; i++) {
        if (i > cnts[1])
            break;
    
        // cout << i << ": " << k << ' ' << i << ' ' << mf.combi(k, i) << endl;
        // cout << i << ": " << cnts[1] << ' ' << i << ' ' << mf.combi(cnts[1], i) << endl;
        // cout << i << ": " << cnts[0] << ' ' << k - i << ' ' << mf.combi(cnts[0], k - i) << endl;
        
        ans += mf.combi(cnts[1], i) * mf.combi(cnts[0], k - i) % MOD;
        ans %= MOD;
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