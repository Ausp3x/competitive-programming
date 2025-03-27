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
    int n, q;
    cin >> n >> q;
    map<int, bool> is_no, is_maybe;

    while (q--) {
        int k;
        cin >> k;
        vector<int> V(k);
        for (int &v : V)
            cin >> v;
        int m;
        cin >> m;

        if (m % 2 == 0) {
            for (int v : V) {
                is_no[v] = true;
                if (is_maybe.contains(v))
                    is_maybe.erase(v);
            }
        } else {
            map<int, bool> new_is_maybe;
            for (int v : V)
                if ((is_maybe.empty() || is_maybe.contains(v)) && !is_no.contains(v))    
                    new_is_maybe[v] = true;
            is_maybe = new_is_maybe;
        }
    }

    if (is_maybe.empty()) {
        if (is_no.size() == n - 1) 
            cout << 1 << ' ' << n - 1 << ' ' << 0 << endl;
        else
            cout << 0 << ' ' << is_no.size() << ' ' << n - is_no.size() << endl;
    } else {
        if (is_maybe.size() == 1)
            cout << 1 << ' ' << n - 1 << ' ' << 0 << endl;
        else
            cout << 0 << ' ' << n - is_maybe.size() << ' ' << is_maybe.size() << endl;
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