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

unordered_map<lng, bool> chks;

void solve() {
    lng n;
    cin >> n;

    // k^2 + k + 1 = n
    // k^2 + k - n + 1
    // k = (-1 + sqrt(4n - 3)) / 2
    
    bool is_square = (lng(sqrt(4 * n - 3)) * lng(sqrt(4 * n - 3)) == 4 * n - 3);
    bool is_div_by_2 = (lng(sqrt(4 * n - 3)) % 2 == 1); 
    if (is_square && is_div_by_2) {
        lng k = (-1 + lng(sqrt(4 * n - 3))) / 2;

        if (k > 1) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << (chks[n] ? "YES" : "NO") << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (lll k = 2; k <= 1'000'000; k++) {
        lll pow = k * k;
        lll cur = 1 + k + k * k;
        chks[cur] = true;
        // cout << lng(cur) << ' ';
        while (cur + pow * k <= 1'000'000'000'000'000'000) {
            pow *= k;
            cur += pow;
            chks[cur] = true;
            // cout << lng(cur) << ' ';
        }
        // cout << endl;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}