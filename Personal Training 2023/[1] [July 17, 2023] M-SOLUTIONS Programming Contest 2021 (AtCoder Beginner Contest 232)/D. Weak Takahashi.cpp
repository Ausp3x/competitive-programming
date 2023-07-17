// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define TROUBLESHOOT

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h + 1, vector<char>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    queue<pair<int, int>> bfs;
    vector<vector<bool>> vst(h + 1, vector<bool>(w + 1));
    bfs.push({1, 1});
    vst[1][1] = true;
    while (!bfs.empty()) {
        auto [i, j] = bfs.front();
        bfs.pop();
        
        // if (i + j - 1 > ans) {
        //     cout << i << ' ' << j << endl;
        //     ans = i + j - 1;
        // }

        ans = max(ans, i + j - 1);

        if (j < w) {
            if (grid[i][j + 1] != '#' && !vst[i][j + 1]) {
                bfs.push({i, j + 1});
                vst[i][j + 1] = true;
            }
        }

        if (i < h) {
            if (grid[i + 1][j] != '#' && !vst[i + 1][j]) {
                bfs.push({i + 1, j});
                vst[i + 1][j] = true;
            }
        }
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef TROUBLESHOOT
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef TROUBLESHOOT
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef TROUBLESHOOT
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}