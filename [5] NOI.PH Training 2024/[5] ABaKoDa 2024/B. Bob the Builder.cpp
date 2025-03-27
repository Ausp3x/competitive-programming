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

vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void solve() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r + 2, vector<char>(c + 2, '.'));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> grid[i][j];

    int ans = 0;
    vector<vector<bool>> good(r + 2, vector<bool>(c + 2));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) {
            if (grid[i][j] != '#')
                continue;

            bool chk = false;
            for (auto &[di, dj] : dir) 
                chk |= grid[i + di][j + dj] == '#';
            
            ans += chk;
            good[i][j] = chk;
        }

    int max_add = 0;
    for (int i = 1; i <= r; i++) 
        for (int j = 1; j <= c; j++) {
            if (grid[i][j] == '#')
                continue;

            bool chk = false;
            for (auto &[di, dj] : dir)
                chk |= grid[i + di][j + dj] == '#';
            
            if (!chk)
                continue;

            int add = 1;
            for (auto &[di, dj] : dir)
                add += (grid[i + di][j + dj] == '#' && !good[i + di][j + dj]);
        
            max_add = max(max_add, add);
        }

    cout << 2 * (ans + max_add) << endl;

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