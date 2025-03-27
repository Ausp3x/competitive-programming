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
    int n, m;
    lng L;
    cin >> n >> m >> L;
    vector<pair<lng, lng>> hurdles(n);
    for (auto &[l, r] : hurdles)
        cin >> l >> r;
    deque<pair<lng, lng>> power_ups(m);
    for (auto &[x, v] : power_ups)
        cin >> x >> v;

    sort(hurdles.begin(), hurdles.end());

    lng max_len = 0;
    for (int i = 0; i < m; i++)
        max_len = max(max_len, hurdles[i].se - hurdles[i].fi + 1);

    int ans = 0;
    lng k = 1;
    priority_queue<lng> to_add;
    for (int i = 0; i < n; i++) {    
        while (!power_ups.empty() && power_ups.front().fi < hurdles[i].fi) {
            to_add.push(power_ups.front().se);
            power_ups.pop_front();
        }

        if (k > hurdles[i].se - hurdles[i].fi + 1)
            continue;
        
        lng len = hurdles[i].se - hurdles[i].fi + 1;
        while (!to_add.empty() && k <= len) {
            ans++;
            k += to_add.top();
            to_add.pop();
        }
        
        if (k <= len) {
            cout << -1 << endl;
            return;
        }
    }
    
    cout << ans << endl;

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