// 人外有人，天外有天
// author: Ausp3x
    
#pragma GCC optimize("O3, fast-math")
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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
    
int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;
    
int const MOD = 998244353;
    
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
        if (y > x || y < 0) {
            return 0;
        }
    
        return fac[x] * inv_fac[y] % MOD * inv_fac[x - y] % MOD;
    }
    
    lng permu(int x, int y) {
        if (y > x || y < 0) {
            return 0;
        }
            
        return fac[x] * inv_fac[x - y] % MOD;
    }
};
    
ModFac mf(2'000'005, MOD);
    
void solve() {
    lng a, b, c, d;
    cin >> a >> b >> c >> d;
    
    if (abs(a - b) > 1) {
        cout << 0 << endl;
        return;
    }
    
    if (a == 0 && b == 0) {
        if (c > 0 && d > 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return;
    }
    
    lng e = (a + b + 1) / 2;
    if (a != b) {
        cout << mf.combi(c + e - 1, e - 1) * mf.combi(d + e - 1, e - 1) % MOD << endl; 
    } else {
        lng f = e / 2;
        cout << (mf.combi(c + e, e) * mf.combi(d + e - 1, e - 1) % MOD + mf.combi(c + e - 1, e - 1) * mf.combi(d + e, e) % MOD) % MOD << endl;
    }
    
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