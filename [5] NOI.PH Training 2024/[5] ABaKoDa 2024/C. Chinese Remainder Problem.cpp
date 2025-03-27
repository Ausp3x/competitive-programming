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

void solve() {
    lng n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<lng> A(n);
    for (lng &a : A) {
        cin >> a;
        
        if (a <= k) {
            cout << -1 << endl;
            return;
        }
    }

    if (l <= k && k <= r) {
        cout << k << endl;
        return;
    }

    lll a_lcm = A[0];
    for (int i = 1; i < n; i++) {
        lll g = __gcd(a_lcm, lll(A[i]));
        a_lcm = a_lcm * A[i] / g;
    
        if (a_lcm > 10'000'000'000) {
            cout << -1 << endl;
            return;
        }
    }

    lng ans = (l + a_lcm - 1) / a_lcm * a_lcm + k;
    while (ans - a_lcm >= l)
        ans -= a_lcm; 
    if (ans > r) {
        cout << -1 << endl;
        return;
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