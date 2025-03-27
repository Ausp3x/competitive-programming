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

int const MOD = 1'000'000'007;

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

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> cnts;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        cnts[a]++;
    }

    vector<int> A = {0};
    vector<lng> B = {1};
    for (auto &[k, v] : cnts) {
        A.pb(k);
        B.pb(v);
    }
    int len = A.size();
    for (int i = 1; i < len; i++) {
        B[i] *= B[i - 1];
        B[i] %= MOD;
    }
    
    lng ans = 0;
    for (int i = 1; i + m - 1 < len; i++) {
        int j = i + m - 1;
        if (A[j] - A[i] >= m)
            continue;

        // cout << A[i] << ' ' << A[j] << ' ' << B[j] * modPow(B[i - 1], MOD - 1) << endl;
        
        ans += B[j] * modPow(B[i - 1], MOD - 2) % MOD;
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