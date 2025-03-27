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

map<char, pair<int, int>> dir = {{'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}};

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    if (a == 0 && b == 0) {
        cout << "YES" << endl;
        return;
    }

    int len = s.size();
    int c = 0, d = 0;

    for (int i = 0; i < 50000; i++) {
        c += dir[s[i % len]].fi;
        d += dir[s[i % len]].se;

        if (c == a && d == b) {
            cout << "YES" << endl;
            return;
        }
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