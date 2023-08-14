// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

vector<pair<int, int>> findHamiltonianPath(int end_i, int end_j, int grid_h, int grid_w) {
    vector<pair<int, int>> res;

    if (grid_h == 2) {
        for (int j = 1; j <= end_j - 1; j++) {
            res.push_back({1, j});
            res.push_back({2, j});
        }
        
        res.push_back({3 - end_i, end_j});
        
        for (int j = end_j + 1; j <= grid_w; j++) {
            res.push_back({1, j});
        }
        
        for (int j = grid_w; j >= end_j + 1; j--) {
            res.push_back({2, j});
        }

        res.push_back({end_i, end_j});
    } else if (grid_w == 2 || end_j == 1 || (end_i == grid_h && end_j == 2)) {
        res = findHamiltonianPath(end_j, end_i, grid_w, grid_h);
        
        for (auto &[i, j] : res) {
            swap(i, j);
        }
    } else {
        for (int i = 1; i <= grid_h; i++) {
            res.push_back({i, 1});
        }

        vector<pair<int, int>> sub_res = findHamiltonianPath(grid_h - end_i + 1, end_j - 1, grid_h, grid_w - 1);

        for (auto &[i, j] : sub_res) {
            i = grid_h - i + 1;
            j++;
        }

        res.insert(res.end(), sub_res.begin(), sub_res.end());
    }

    return res;
} 


void solve() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    vector<pair<int, int>> ans = findHamiltonianPath(a, b, h, w);
    for (auto [i, j] : ans) {
        cout << i << ' ' << j << endl;
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