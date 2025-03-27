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

void solve() {
    int n, x;
    cin >> n >> x;

    if (n == 1) {
        cout << "YES" << endl;
        cout << x << endl;
        return;
    }

    if (n == 2 && x == 0) {
        cout << "NO" << endl;
        return;
    }

    if (n == 2) {
        cout << "YES" << endl;
        cout << 0 << ' ' << x << endl;
        return;
    }
    
    cout << "YES" << endl;
    int y = 0;
    for (int i = 1; i <= n - 3; i++) {
        y ^= i;
        cout << i << ' ';
    }

    int mx = 1ll << 17;
    if (y == x) {
        cout << mx << ' ' << 2 * mx << ' ' << (mx ^ (2 * mx)) << endl;
    } else {
        cout << 0 << ' ' << mx << ' ' << (mx ^ x ^ y) << endl;
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