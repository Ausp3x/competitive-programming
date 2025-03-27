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
    vector<lng> X(n), Y(n), H(n);
    for (int i = 0; i < n; i++) 
        cin >> X[i] >> Y[i] >> H[i];

    for (lng c_x = 0; c_x <= 100; c_x++)
        for (lng c_y = 0; c_y <= 100; c_y++) {
            lng upper_bound = INF64;
            map<lng, int> cnts;
            for (int i = 0; i < n; i++) {
                lng h = H[i] + abs(X[i] - c_x) + abs(Y[i] - c_y);
                if (H[i] == 0)
                    upper_bound = min(upper_bound, h);
                else {
                    cnts[h]++;
                }
            }

            if (cnts.size() > 1)
                continue;

            if (cnts.begin()->fi > upper_bound)
                continue;

            cout << c_x << ' ' << c_y << ' ' << cnts.begin()->fi << endl;
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