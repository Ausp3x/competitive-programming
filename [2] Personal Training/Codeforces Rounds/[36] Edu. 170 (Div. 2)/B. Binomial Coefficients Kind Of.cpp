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

int const MOD = 1'000'000'007;

lng modPow(lng x, lng y, int mod) {
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
    int t;
    cin >> t;
    vector<int> N(t);
    for (int &n : N)
        cin >> n;
    vector<int> K(t);
    for (int &k : K)
        cin >> k;

    for (int i = 0; i < t; i++) {
        if (K[i] == N[i]) {
            cout << 1 << endl;
            continue;
        }

        cout << modPow(2, K[i], MOD) << endl; 
    }
    
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