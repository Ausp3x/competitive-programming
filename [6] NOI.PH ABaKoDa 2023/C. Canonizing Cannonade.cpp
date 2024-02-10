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
    int r, c, m, k;
    cin >> r >> c >> m >> k;

    if (m < k) {
        cout << "NO" << endl;
        return;
    }

    if (m > k * max(r, c)) {
        cout << "NO" << endl;
        return;
    }

    if (min(r, c) < k) {
        cout << "NO" << endl;
        return;
    }

    vector<vector<char>> grid(r, vector<char>(c, '.'));
    for (int i = 0; i < min(k, min(r, c)); i++) {
        grid[i][i] = '#';
    }
    m -= min(k, min(r, c));
    
    if (r <= c) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '.' && m > 0) {
                    grid[i][j] = '#';
                    m--;                
                } else if (m == 0) {
                    goto exit;
                }
            }
        }
    } else {
        for (int j = 0; j < k; j++) {
            for (int i = 0; i < r; i++) {
                if (grid[i][j] == '.' && m > 0) {
                    grid[i][j] = '#';
                    m--;      
                } else if (m == 0) {
                    goto exit;
                }
            }
        }
    } 
exit:

    cout << "YES" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << grid[i][j];
        }
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