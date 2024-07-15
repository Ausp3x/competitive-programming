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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    while (true) {
        bool isDone = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int cur = 0;
                if (i > 0)
                    if (grid[i][j] > grid[i - 1][j])
                        cur = max(cur, grid[i - 1][j]);
                    else 
                        continue;
                if (i < n - 1)
                    if (grid[i][j] > grid[i + 1][j])
                        cur = max(cur, grid[i + 1][j]);
                    else
                        continue;
                if (j > 0)
                    if (grid[i][j] > grid[i][j - 1])
                        cur = max(cur, grid[i][j - 1]);
                    else
                        continue;
                if (j < m - 1)
                    if (grid[i][j] > grid[i][j + 1])
                        cur = max(cur, grid[i][j + 1]);
                    else
                        continue;

                grid[i][j] = cur;
                isDone = cur == 0;           
            }

        if (isDone)
            break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << grid[i][j] << ' ';
        cout << endl;
    }

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