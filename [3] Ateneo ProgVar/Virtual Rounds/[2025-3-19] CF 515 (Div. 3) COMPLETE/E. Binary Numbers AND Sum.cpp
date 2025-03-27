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

lng modPow(lng x, lng y, lng mod) {
    lng res = 1;
    while (y > 0) {
        if (y & 1) {
            res *= x;
            res %= mod;
        }

        y >>= 1;
        x *= x;
        x %= mod;
    }

    return (res + mod) % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    if (n < m) {
        a += string(m - n, '0');
    } else if (m < n) {
        b += string(n - m, '0');
    }

    int l = max(n, m), cnt = 0;
    lng ans = 0;
    for (int i = l - 1; i >= 0; i--) {
        cnt += (b[i] == '1');
    
        if (a[i] == '0' || cnt == 0)
            continue;

        ans += (cnt * modPow(2, i, MOD)) % MOD;
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