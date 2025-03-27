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

int getDis(pair<int, int> x, pair<int, int> y) {
    return abs(x.fi - y.fi) + abs(x.se - y.se);
}

void solve() {
    int n;
    cin >> n;
    map<int, set<pair<int, int>>> M;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        M[max(x, y)].insert({x, -y});
    }

    int len = M.size() + 1, i = 1;
    pair<int, int> l_prv = {0, 0}, r_prv = {0, 0};
    vector<vector<lng>> dp(len, vector<lng>(2, INF64));
    dp[0][0] = dp[0][1] = 0;
    for (auto &[k, v] : M) {
        pair<int, int> l = *v.begin();
        pair<int, int> r = *v.rbegin();
        l.se = abs(l.se);
        r.se = abs(r.se);

        int d = getDis(l, r);

        dp[i][0] = min({
            dp[i][0],
            dp[i - 1][0] + getDis(l_prv, r) + d,
            dp[i - 1][1] + getDis(r_prv, r) + d
        });

        dp[i][1] = min({
            dp[i][1],
            dp[i - 1][0] + getDis(l_prv, l) + d,
            dp[i - 1][1] + getDis(r_prv, l) + d
        });
        
        i++;
        l_prv = l;
        r_prv = r;
    }

    cout << min(dp[len - 1][0], dp[len - 1][1]) << endl;
    
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