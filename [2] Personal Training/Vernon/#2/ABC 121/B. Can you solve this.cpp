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
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> B(m);
    for (int &b : B)
        cin >> b;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = c;
        for (int j = 0; j < m; j++)
            cur += A[i][j] * B[j];

        ans += cur > 0;
    }

    cout << ans << endl;

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