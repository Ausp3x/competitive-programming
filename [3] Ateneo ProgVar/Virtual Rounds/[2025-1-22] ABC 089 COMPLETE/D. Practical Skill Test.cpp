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
    int h, w, d;
    cin >> h >> w >> d;
    vector<vector<int>> A(h + 2, vector<int>(w + 2, INF64));
    vector<pair<int, int>> V(h * w + 1);
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            cin >> A[i][j];
            V[A[i][j]] = {i, j};
        }

    vector<int> ans(h * w + 1);
    for (int i = 1; i <= d; i++) 
        for (int j = i + d; j <= h * w; j += d) 
            ans[j] = ans[j - d] + abs(V[j].fi - V[j - d].fi) + abs(V[j].se - V[j - d].se);
    
    // for (int x : ans)
    //     cout << x << ' ';
    // cout << endl;

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << ans[r] - ans[l] << endl;
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