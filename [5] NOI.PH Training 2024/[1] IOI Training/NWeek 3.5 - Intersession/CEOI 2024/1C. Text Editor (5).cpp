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
typedef __int128     lli;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    int sl, sc;
    cin >> sl >> sc;
    int el, ec;
    cin >> el >> ec;
    vector<int> C(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
        C[i]++;
    }

    if (n <= 2) {
        if (sl == 2 && el == 2) {
            cout << 0 << endl;
            return;
        }

        if (sl == 1 && el == 2) {
            cout << 1 << endl;
            return;
        }

        if (sl == 2 && el == 1) {
            cout << min(ec, C[1] - ec + 1) << endl;
            return;
        }

        cout << min({abs(ec - sc), 2 + ec - 1, 2 + C[1] - ec}) << endl;

        return;
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