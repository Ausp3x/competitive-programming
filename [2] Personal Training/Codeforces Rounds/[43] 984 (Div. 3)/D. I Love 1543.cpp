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
    cin >> n >> m;
    vector<vector<char>> grid(n + 2, vector<char>(m + 2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];

    vector<deque<char>> layers(n / 2 + 1);
    for (int i = 1; i <= n / 2; i++) {
        for (int j = m / 2; j >= 1; j--) {
            int l = min({i, j, n - i + 1, m - j + 1});
            layers[l].push_front(grid[i][j]);
        }
    
        for (int j = m / 2 + 1; j <= m; j++) {
            int l = min({i, j, n - i + 1, m - j + 1});
            layers[l].push_back(grid[i][j]);
        }
    }
    for (int i = n / 2 + 1; i <= n; i++) {
        for (int j = 1; j <= m / 2; j++) {
            int l = min({i, j, n - i + 1, m - j + 1});
            layers[l].push_front(grid[i][j]);
        }
    
        for (int j = m; j >= m / 2 + 1; j--) {
            int l = min({i, j, n - i + 1, m - j + 1});
            layers[l].push_back(grid[i][j]);
        }
    }

    // for (auto L : layers) {
    //     for (char c : L)
    //         cout << c;
    //     cout << endl;
    // }

    int ans = 0;
    for (int i = 1; i <= n / 2; i++) {
        int len = layers[i].size();
        for (int j = 0; j < len; j++) {
            string cur = "";
            cur += layers[i][j];
            cur += layers[i][(j + 1) % len];
            cur += layers[i][(j + 2) % len];
            cur += layers[i][(j + 3) % len];
        
            ans += cur == "1543";
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