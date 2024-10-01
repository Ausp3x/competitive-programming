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
    int n, m, q;
    cin >> n >> m >> q;
    indexed_set<int> B;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;

        B.insert(b);
    }

    // cout << *B.begin() << ' ' << *B.rbegin() << endl;

    while (q--) {
        int a;
        cin >> a;

        // cout << a << ' ';

        if (a < *B.begin()) {
            cout << *B.begin() - 1 << endl;
            continue; 
        }

        if (a > *B.rbegin()) {
            cout << n - *B.rbegin() << endl;
            continue;
        }

        int l = *B.find_by_order(B.order_of_key(a) - 1);
        int r = *B.find_by_order(B.order_of_key(a));

        // cout << l << ' ' << r << ' ';

        cout << (r - l) / 2 << endl;
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