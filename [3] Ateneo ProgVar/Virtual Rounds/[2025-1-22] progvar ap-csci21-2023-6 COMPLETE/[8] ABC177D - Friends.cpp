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
    int n, m;
    cin >> n >> m;
    vector<int> cnts(n + 1);
    vector<pair<int, int>> edges(m);
    vector<vector<bool>> adjm(n + 1, vector<bool>(n + 1));
    for (auto &[a, b] : edges) {
        cin >> a >> b;

        cnts[a]++;
        adjm[a][b] = true;
        cnts[b]++;
        adjm[b][a] = true;
    }

    int ans = INF32;
    for (auto &[a, b] : edges) {
        for (int c = 1; c <= n; c++) {
            if (c == a || c == b)
                continue;

            if (!adjm[a][c] || !adjm[b][c])
                continue;

            ans = min(ans, cnts[a] + cnts[b] + cnts[c] - 6);
        }
    }

    cout << (ans == INF32 ? -1 : ans) << endl;
    
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