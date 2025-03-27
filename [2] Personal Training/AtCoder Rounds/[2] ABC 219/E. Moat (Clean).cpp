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

int n = 4;
bool is_valid(int grid) {
    pair<int, int> idx = {-1, -1};
    vector<vector<bool>> grid_full(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid_full[i][j] = grid & (1 << (i * n + j));
            
            if (grid_full[i][j] && idx.first == -1) {
                idx = {i, j};
            }
        }
    }
    
    vector<pair<int, int>> di_djs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int cnt = 0;
    stack<pair<int, int>> s;
    vector<vector<bool>> vst(n, vector<bool>(n));
    s.push(idx);
    vst[idx.first][idx.second] = true;
    cnt++;
    while (!s.empty()) {
        auto [i, j] = s.top();
        s.pop();

        for (auto &[di, dj] : di_djs) {
            if (i + di < 0 || i + di >= n || j + dj < 0 || j + dj >= n) {
                continue;
            }

            if (grid_full[i + di][j + dj] && !vst[i + di][j + dj]) {\
                s.push({i + di, j + dj});
                vst[i + di][j + dj] = true;
                cnt++;
            }
        }
    }

    if (cnt != __builtin_popcount(grid)) {
        return false;
    }

    bool is_closed = false;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (grid_full[i][j] || vst[i][j]) {
                continue;
            }

            bool cur_is_closed = true;
            s.push({i, j});
            vst[i][j] = true;
            while (!s.empty()) {
                auto [i, j] = s.top();
                s.pop();

                if (i < 1 || i >= n - 1 || j < 1 || j >= n - 1) {
                    cur_is_closed = false;
                }

                for (auto &[di, dj] : di_djs) {
                    if (i + di < 0 || i + di >= n || j + dj < 0 || j + dj >= n) {
                        continue;
                    }

                    if (!grid_full[i + di][j + dj] && !vst[i + di][j + dj]) {\
                        s.push({i + di, j + dj});
                        vst[i + di][j + dj] = true;
                    }
                }
            }

            is_closed |= cur_is_closed;
        }
    }

    if (is_closed) {
        return false;
    }

    return true;
}

void solve() {
    int grid = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool a;
            cin >> a;
            grid |= a << (i * n + j);
        }
    }

    int ans = 0;
    for (int cur_grid = 1; cur_grid < (1 << 16); cur_grid++) {
        if ((cur_grid & grid) == grid) {
            ans += is_valid(cur_grid);
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