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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    map<pair<int, int>, int> cnts;
    for (int i = 0; i < n; i++) {
        int a = (A[i] % x + x) % x;
        int b = (A[i] % y + y) % y;

        // cout << a << ' ' << b << endl;

        cnts[{a, b}]++;
    }

    lng ans = 0;
    for (int i = 0; i < n; i++) {
        int a = (A[i] % x + x) % x;
        int b = (A[i] % y + y) % y;

        if (a == 0 || 2 * a == x) {
            ans += cnts[{a, b}] - 1;
            // cout << i << ": " << cnts[{a, b}] - 1 << ' ' << a << ' ' << b << endl;
        } else {
            ans += cnts[{x - a, b}];
            // cout << i << ": " << cnts[{x - a, b}] << ' ' << x - a << ' ' << b << endl;
        }

        cnts[{a, b}]--;
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