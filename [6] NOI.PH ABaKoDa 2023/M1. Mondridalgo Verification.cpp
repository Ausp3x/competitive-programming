// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r + 2, vector<char>(c + 2, 'X'));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> grid[i][j];
        }
    }

    bool a_edge = false, c_edge = false;
    for (int i = 1; i <= r; i++) {
        if (grid[i][1] == 'A' || grid[i][c] == 'A') {
            a_edge = true;
        }
    
        if (grid[i][1] == 'C' || grid[i][c] == 'C') {
            c_edge = true;
        }
    }
    for (int j = 1; j <= c; j++) {
        if (grid[1][j] == 'A' || grid[r][j] == 'A') {
            a_edge = true;
        }
    
        if (grid[1][j] == 'C' || grid[r][j] == 'C') {
            c_edge = true;
        }
    }

    if ((!a_edge) || (!c_edge)) {
        cout << "NO" << endl;
        return;
    }

    int a_partitions = 0;
    vector<vector<bool>> vst(r + 2, vector<bool>(c + 2, false));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (grid[i][j] != 'A') {
                continue;
            }

            if (vst[i][j]) {
                continue;
            }

            a_partitions++;

            queue<pair<int, int>> q;
            q.push({i, j});
            vst[i][j] = true;
            while (!q.empty()) {
                auto [i_cur, j_cur] = q.front();
                q.pop();

                vector<pair<int, int>> di_djs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                for (auto [di, dj] : di_djs) {
                    if (grid[i_cur + di][j_cur + dj] != 'A') {
                        continue;
                    }
                    
                    if (vst[i_cur + di][j_cur + dj]) {
                        continue;
                    }

                    q.push({i_cur + di, j_cur + dj});
                    vst[i_cur + di][j_cur + dj] = true;
                }
            }
        }
    }

    if (a_partitions != 1) {
        cout << "NO" << endl;
        return;
    }

    int c_partitions = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (grid[i][j] != 'C') {
                continue;
            }

            if (vst[i][j]) {
                continue;
            }

            c_partitions++;

            queue<pair<int, int>> q;
            q.push({i, j});
            vst[i][j] = true;
            while (!q.empty()) {
                auto [i_cur, j_cur] = q.front();
                q.pop();

                vector<pair<int, int>> di_djs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                for (auto [di, dj] : di_djs) {
                    if (grid[i_cur + di][j_cur + dj] != 'C') {
                        continue;
                    }
                    
                    if (vst[i_cur + di][j_cur + dj]) {
                        continue;
                    }

                    q.push({i_cur + di, j_cur + dj});
                    vst[i_cur + di][j_cur + dj] = true;
                }
            }
        }
    }
    
    if (c_partitions != 1) {
        cout << "NO" << endl;
        return;
    }

    int ans = 0;
    for (int i = 1; i < r; i++) {
        int prv = -1;
        for (int j = 1; j <= c; j++) {
            if ((grid[i][j] == 'A' && grid[i + 1][j] == 'C') || (grid[i][j] == 'C' && grid[i + 1][j] == 'A')) {
                if (j - prv > 1) {
                    ans++;
                }
                prv = j;
            }
        }
    }
    for (int j = 1; j < c; j++) {
        int prv = -1;
        for (int i = 1; i <= r; i++) {
            if ((grid[i][j] == 'A' && grid[i][j + 1] == 'C') || (grid[i][j] == 'C' && grid[i][j + 1] == 'A')) {
                if (i - prv > 1) {
                    ans++;
                }
                prv = i;
            }
        }
    }
    
    cout << "YES" << endl;
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