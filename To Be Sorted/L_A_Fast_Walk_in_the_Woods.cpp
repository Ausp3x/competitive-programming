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
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

map<char, int> dir_to_idx = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> idx_to_loc(n + 1);
    map<pair<int, int>, int> loc_to_idx;
    for (int i = 1; i <= n; i++) {
        cin >> idx_to_loc[i].fi >> idx_to_loc[i].se;
        loc_to_idx[idx_to_loc[i]] = i;
    }

    // N, E, S, W (90º CW turns)
    vector<vector<int>> adjl(n + 1, vector<int>(4));
    map<pair<int, int>, int> edge_interests;
    for (int _ = 0; _ < m; _++) {
        int i, j, k;
        cin >> i >> j >> k;

        if (idx_to_loc[i].fi > idx_to_loc[j].fi) {
            adjl[i][2] = j;
            adjl[j][0] = i;
        } else if (idx_to_loc[i].fi < idx_to_loc[j].fi) {
            adjl[i][0] = j;
            adjl[j][2] = i;
        } else if (idx_to_loc[i].se > idx_to_loc[j].se) {
            adjl[i][3] = j;
            adjl[j][1] = i;
        } else if (idx_to_loc[i].se < idx_to_loc[j].se) {
            adjl[i][1] = j;
            adjl[j][3] = i;
        }
        edge_interests[{min(i, j), max(i, j)}] = k;
    }

    int cur;
    char chr_dir;
    cin >> cur >> chr_dir;
    int dir = dir_to_idx[chr_dir];
    while (m > 0) {
        int ord = 1;
        vector<pair<int, int>> ord_to_loc;
        map<pair<int, int>, int> loc_to_ord;
        ord_to_loc.pb({-1, -1});
        while (true) {
            vector<pair<int, int>> nxts;
            if (adjl[cur][(dir + 3) % 4] != 0)
                nxts.pb({adjl[cur][(dir + 3) % 4], (dir + 3) % 4});
            if (adjl[cur][dir] != 0)
                nxts.pb({adjl[cur][dir], dir});
            if (adjl[cur][(dir + 1) % 4] != 0)
                nxts.pb({adjl[cur][(dir + 1) % 4], (dir + 1) % 4});
        
            
        }
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