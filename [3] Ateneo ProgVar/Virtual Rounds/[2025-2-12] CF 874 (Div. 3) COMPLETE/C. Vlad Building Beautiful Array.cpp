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
    int n;
    cin >> n;
    int mn_evn = INF32, mn_odd = INF32;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
        if (a % 2 == 0)
            mn_evn = min(mn_evn, a);
        else
            mn_odd = min(mn_odd, a);
    }

    if (mn_evn == INF32 || mn_odd == INF32) {
        cout << "YES" << endl;
        return;
    }

    if (mn_odd < mn_evn) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
    
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