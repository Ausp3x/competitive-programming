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
    string s;
    cin >> s;
    s = 'X' + s;
    int n = s.size() - 1;
    
    set<int> idxs_1100;
    for (int i = 1; i <= n - 3; i++) 
        if (s.substr(i, 4) == "1100")
            idxs_1100.insert(i);

    int q;
    cin >> q;
    while (q--) {
        int idx;
        char v;
        cin >> idx >> v;

        s[idx] = v;

        for (int i = max(idx - 3, 1); i <= min(idx, n - 3); i++)
            if (s.substr(i, 4) == "1100") {
                idxs_1100.insert(i);
            } else {
                if (idxs_1100.find(i) != idxs_1100.end())
                    idxs_1100.erase(i);
            }

        cout << (idxs_1100.size() ? "YES" : "NO") << endl;
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