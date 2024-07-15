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

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> pit0;

int tilt(int i, int j, char d) {
    if (grid[i][j] < 'A' || grid[i][j] > 'Z')
        return 1;
    
    if (d == 'N') {
        if (i == 0)
            return 1;

        if ('1' <= grid[i - 1][j] && grid[i - 1][j] <= '9') {
            if (grid[i - 1][j] == '1')
                pit0[i - 1][j] = true;

            grid[i - 1][j]--;
            grid[i][j] = '.';

            return 1;
        }

        if (grid[i - 1][j] != '.' && grid[i - 1][j] != '0')
            return 1;

        swap(grid[i - 1][j], grid[i][j]);
        grid[i][j] = '.';

        return 0;
    } else if (d == 'S') {
        if (i == n - 1)
            return 1;

        if ('1' <= grid[i + 1][j] && grid[i + 1][j] <= '9') {
            if (grid[i + 1][j] == '1')
                pit0[i + 1][j] = true;

            grid[i + 1][j]--;
            grid[i][j] = '.';

            return 1;
        }

        if (grid[i + 1][j] != '.' && grid[i + 1][j] != '0')
            return 1;

        swap(grid[i + 1][j], grid[i][j]);
        grid[i][j] = '.';

        return 0;
    } else if (d == 'W') {
        if (j == 0)
            return 1;

        if ('1' <= grid[i][j - 1] && grid[i][j - 1] <= '9') {
            if (grid[i][j - 1] == '1')
                pit0[i][j - 1] = true;

            grid[i][j - 1]--;
            grid[i][j] = '.';

            return 1;
        }

        if (grid[i][j - 1] != '.' && grid[i][j - 1] != '0')
            return 1;

        swap(grid[i][j - 1], grid[i][j]);
        grid[i][j] = '.';

        return 0;
    } else if (d == 'E') {
        if (j == m - 1)
            return 1;

        if ('1' <= grid[i][j + 1] && grid[i][j + 1] <= '9') {
            if (grid[i][j + 1] == '1')
                pit0[i][j + 1] = true;
            
            grid[i][j + 1]--;
            grid[i][j] = '.';

            return 1;
        }

        if (grid[i][j + 1] != '.' && grid[i][j + 1] != '0')
            return 1;

        swap(grid[i][j + 1], grid[i][j]);
        grid[i][j] = '.';

        return 0;
    }

    return 1;
}

void solve() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    pit0.resize(n, vector<bool>(m));

    string s;
    cin >> s;
    for (char c : s)
        if (c == 'N')
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    int ic = i, jc = j;
                    while (!tilt(ic, jc, c))
                        ic--;
                }
        else if (c == 'S')
            for (int i = n - 1; i >= 0; i--)
                for (int j = 0; j < m; j++) {
                    int ic = i, jc = j;
                    while (!tilt(ic, jc, c))
                        ic++;
                }
        else if (c == 'W')
            for (int j = 0; j < m; j++)
                for (int i = 0; i < n; i++) {
                    int ic = i, jc = j;
                    while (!tilt(ic, jc, c))
                        jc--;
                }
        else if (c == 'E')
            for (int j = m - 1; j >= 0; j--)
                for (int i = 0; i < n; i++) {
                    int ic = i, jc = j;
                    while (!tilt(ic, jc, c))
                        jc++;
                }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << (grid[i][j] == '.' && pit0[i][j] ? '0' : grid[i][j]);
        cout << endl;
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