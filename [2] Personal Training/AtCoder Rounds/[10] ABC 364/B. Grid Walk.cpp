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

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int H, W;
    cin >> H >> W;
    int S_i, S_j;
    cin >> S_i >> S_j;
    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> grid[i][j];

    S_i--;
    S_j--;

    string X;
    cin >> X;
    for (char x : X) {
        if (x == 'L') {
            if (S_j > 0)
                if (grid[S_i][S_j - 1] == '.')
                    S_j--;
        } else if (x == 'R') {
            if (S_j < W - 1)
                if (grid[S_i][S_j + 1] == '.')
                    S_j++;
        } else if (x == 'U') {
            if (S_i > 0)
                if (grid[S_i - 1][S_j] == '.')
                    S_i--;
        } else if (x == 'D') {
            if (S_i < H - 1)
                if (grid[S_i + 1][S_j] == '.')
                    S_i++;
        }
    }

    S_i++;
    S_j++;

    cout << S_i << ' ' << S_j << endl;
    
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