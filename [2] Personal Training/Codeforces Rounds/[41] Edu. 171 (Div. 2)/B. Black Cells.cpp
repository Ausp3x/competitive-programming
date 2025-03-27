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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<lng> A(n);
    for (lng &a : A)
        cin >> a;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    if (n % 2 == 0) {
        lng ans = 1;
        for (int i = 0; i < n; i += 2)
            ans = max(ans, A[i + 1] - A[i]);
    
        cout << ans << endl;
        return;
    }

    lng ans = INF64;
    for (int i = 0; i < n; i += 2) {
        lng cur = 1;
        for (int j = 0; j < i; j += 2)
            cur = max(cur, A[j + 1] - A[j]);
        for (int j = i + 1; j < n; j += 2)
            cur = max(cur, A[j + 1] - A[j]);

        ans = min(ans, cur);
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