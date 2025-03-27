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

int n;

int numberOfHashtags(auto &grid) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt += grid[i][j] == '#';
        }
    }

    return cnt;
}

bool isTranslationObtainable(auto &i_grid, auto &f_grid) {
    if (numberOfHashtags(i_grid) != numberOfHashtags(f_grid)) {
        return false;
    }
    
    int di = 0, dj = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (f_grid[i][j] == '#') {
                di = i;
                dj = j;
                goto exit;
            }
        }
    }
exit:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i_grid[i][j] == '#') {
                di -= i;
                dj -= j;
                goto exit_2;
            }
        }
    }
exit_2:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i_grid[i][j] != '#') {
                continue;
            }

            if (i + di < 0 || i + di >= n || j + dj < 0 || j + dj >= n) {
                return false;
            }

            if (f_grid[i + di][j + dj] != '#') {
                return false;
            }
        }
    }

    return true;
} 

void solve() {
    cin >> n;
    vector<vector<char>> s_grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s_grid[i][j];
        }
    }
    vector<vector<char>> t_grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t_grid[i][j];
        }
    }

    vector<vector<char>> s_grid_90(n, vector<char>(n)),
                         s_grid_180(n, vector<char>(n)),
                         s_grid_270(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s_grid_90[j][n - i - 1] = s_grid[i][j];
            s_grid_180[n - i - 1][n - j - 1] = s_grid[i][j];
            s_grid_270[n - j - 1][i] = s_grid[i][j];
        }
    }

    cout << (isTranslationObtainable(s_grid, t_grid) || 
             isTranslationObtainable(s_grid_90, t_grid) ||
             isTranslationObtainable(s_grid_180, t_grid) ||
             isTranslationObtainable(s_grid_270, t_grid) ? "Yes" : "No") << endl;

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