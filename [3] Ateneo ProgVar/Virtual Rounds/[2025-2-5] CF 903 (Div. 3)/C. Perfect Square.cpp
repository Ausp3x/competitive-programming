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
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int ans = 0;
    vector<vector<bool>> vst(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (vst[i][j])
                continue;

            vst[i][j] = true;
            vst[j][n - i - 1] = true;
            vst[n - i - 1][n - j - 1] = true;
            vst[n - j - 1][i] = true;

            vector<int> arr = {
                grid[i][j] - 'a',
                grid[j][n - i - 1] - 'a',
                grid[n - i - 1][n - j - 1] - 'a',
                grid[n - j - 1][i] - 'a',
            };
            
            int cur = 0, a_mx = max({arr[0], arr[1], arr[2], arr[3]});
            for (int a : arr)
                cur += a_mx - a;

            ans += cur;
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