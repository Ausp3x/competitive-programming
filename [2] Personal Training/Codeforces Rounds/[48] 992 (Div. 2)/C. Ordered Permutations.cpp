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
    int n;
    lng k;
    cin >> n >> k;
    k--;

    deque<int> left, right;
    for (int i = n - 2; i >= 0; i--) {
        if (i >= 63) {
            left.pb(n - i - 1);
            continue;
        }
        
        if (k >= (1ll << i)) { 
            right.push_front(n - i - 1);
            k -= (1ll << i);
        } else
            left.pb(n - i - 1);
    }

    if (k > 0) {
        cout << -1 << endl;
        return; 
    }

    for (int x : left)
        cout << x << ' ';
    cout << n << ' ';
    for (int x : right)
        cout << x << ' ';
    cout << endl;

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