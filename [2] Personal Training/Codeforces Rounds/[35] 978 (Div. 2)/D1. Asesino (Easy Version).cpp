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
    int n;
    cin >> n;

    for (int i = 1; i + 1 <= n; i += 2) {
        cout << "? " << i << ' ' << i + 1 << endl;
        bool r12;
        cin >> r12;

        cout << "? " << i + 1 << ' ' << i << endl;
        bool r21;
        cin >> r21;

        int q = (i + 1 < n ? n : 1);
        if (r12 != r21) {
            cout << "? " << i << ' ' << q << endl;
            bool riq;
            cin >> riq;

            cout << "? " << q << ' ' << i << endl;
            bool rqi;
            cin >> rqi;

            cout << "! " << (riq != rqi ? i : i + 1) << endl;
            return;
        }
    }
    if (n % 2 == 1) {
        cout << "? " << n - 1 << ' ' << n << endl;
        bool r12;
        cin >> r12;

        cout << "? " << n << ' ' << n - 1 << endl;
        bool r21;
        cin >> r21;

        int q = 1;
        if (r12 != r21) {
            cout << "? " << n - 1 << ' ' << q << endl;
            bool riq;
            cin >> riq;

            cout << "? " << q << ' ' << n - 1 << endl;
            bool rqi;
            cin >> rqi;

            cout << "! " << (riq != rqi ? n - 1 : n) << endl;
            return;
        }
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