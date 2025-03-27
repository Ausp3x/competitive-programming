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

struct FloydWarshall {
    int n;
    vector<vector<lng>> dis;
    
    FloydWarshall(int n, vector<vector<lng>> dis) : n(n), dis(dis) {
        assert(this->dis.size() == this->n + 1);
        for (int i = 0; i <= this->n; i++) {
            assert(this->dis[i].size() == this->n + 1);
        }
    
        runFloydWarshall();
    }
    
    void runFloydWarshall() {
        for (int k = 0; k <= n; k++) {
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
                }
            }
        }
    
        return;
    }
};

vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h + 2, vector<char>(w + 2, '#'));
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> grid[i][j];

    int n = h * w;
    vector<vector<lng>> dis(n + 1, vector<lng>(n + 1, INF64));
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) 
            if (grid[i][j] == '.')
                dis[(i - 1) * w + j - 1][(i - 1) * w + j - 1] = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            if (grid[i][j] == '#')
                continue;

            for (auto [di, dj] : dirs) {
                if (grid[i + di][j + dj] == '#')
                    continue;

                dis[(i - 1) * w + j - 1][(i + di - 1) * w + j + dj - 1] = 1;
            }
        }

    FloydWarshall fw(n, dis);

    lng ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            if (fw.dis[i][j] < INF64) {
                ans = max(ans, fw.dis[i][j]);

                // cout << i / w << ',' << i % w << " -> " << j / w << ',' << j % w << ": " << fw.dis[i][j] << endl;
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