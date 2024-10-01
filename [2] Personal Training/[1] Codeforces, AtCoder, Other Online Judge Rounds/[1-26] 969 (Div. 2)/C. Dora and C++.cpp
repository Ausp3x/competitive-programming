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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> C(n);
    for (int &c : C)
        cin >> c;

    int g = __gcd(a, b);
    map<int, bool> mod_grps;
    for (int i = 0; i < n; i++) 
        mod_grps[C[i] % g] = true;

    // cout << g << endl;

    deque<int> dq;
    for (auto [m, chk] : mod_grps)
        dq.pb(m);
    
    int ans = INF32;
    for (int i = 0; i < mod_grps.size(); i++) {
        ans = min(ans, dq.back() - dq.front());
        dq.pb(dq.front() + g);
        dq.pop_front();
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