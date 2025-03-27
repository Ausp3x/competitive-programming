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
    lng b, c, d;
    cin >> b >> c >> d;

    // only 63 bits are used for storing the value of the integer
    bitset<64> B = b, C = c, D = d;
    lng a = 0;
    for (int i = 0; i < 63; i++) {
        if (B[i] == 1) {
            if (C[i] == 1) {
                if (D[i] == 1) {
                    // ith bit of a is 0
                } else {
                    a += 1ll << i;
                }
            } else {
                if (D[i] == 1) {
                    // guaranteed
                } else {
                    cout << -1 << endl;
                    return;
                }
            }
        } else {
            if (C[i] == 1) {
                if (D[i] == 1) {
                    cout << -1 << endl;
                    return;
                } else {
                    // guaranteed
                }
            } else {
                if (D[i] == 1) {
                    a += 1ll << i;
                } else {
                    // ith bit of a is 0
                }
            }
        }
    }

    cout << a << endl;
    // cout << (a | b) - (a & c) << endl;

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