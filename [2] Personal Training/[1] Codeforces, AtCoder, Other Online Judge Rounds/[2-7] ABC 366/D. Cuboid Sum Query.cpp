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
    int N;
    cin >> N;
    vector<vector<vector<lng>>> A(N + 1, vector<vector<lng>>(N + 1, vector<lng>(N + 1, 0)));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++) {
                cin >> A[i][j][k];
                A[i][j][k] += A[i - 1][j][k]     + A[i][j - 1][k]     + A[i][j][k - 1];
                A[i][j][k] -= A[i - 1][j - 1][k] + A[i - 1][j][k - 1] + A[i][j - 1][k - 1];
                A[i][j][k] += A[i - 1][j - 1][k - 1];
            }

    // for (int i = 1; i <= N; i++)
    //     for (int j = 1; j <= N; j++) {
    //         for (int k = 1; k <= N; k++)
    //             cout << A[i][j][k] << ' ';
    //         cout << endl;
    //     }

    int Q;
    cin >> Q;
    while (Q--) {
        int i1, i2, j1, j2, k1, k2;
        cin >> i1 >> i2 >> j1 >> j2 >> k1 >> k2;

        lng ans = 0;
        ans += A[i2][j2][k2];
        // cout << A[i2][j2][k2] << endl;
        ans -= A[i1 - 1][j2][k2]     + A[i2][j1 - 1][k2]     + A[i2][j2][k1 - 1];
        // cout << A[i1 - 1][j2][k2] << ' ' << A[i2][j1 - 1][k2] << ' ' << A[i2][j2][k1 - 1] << endl;
        ans += A[i1 - 1][j1 - 1][k2] + A[i1 - 1][j2][k1 - 1] + A[i2][j1 - 1][k1 - 1];
        // cout << A[i1 - 1][j1 - 1][k2] << ' ' << A[i1 - 1][j2][k1 - 1] << ' ' << A[i2][j1 - 1][k1 - 1] << endl;
        ans -= A[i1 - 1][j1 - 1][k1 - 1];
        // cout << A[i1 - 1][j1 - 1][k1 - 1] << endl;

        cout << ans << endl;
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