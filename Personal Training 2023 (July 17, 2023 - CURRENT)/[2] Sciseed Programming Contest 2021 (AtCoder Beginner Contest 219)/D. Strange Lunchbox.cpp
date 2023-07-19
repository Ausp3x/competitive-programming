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

int const INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<int> as(n), bs(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i] >> bs[i];
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(301, vector<int>(301, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= y; k++) {
                if (dp[i][j][k] == INF) {
                    continue;
                }

                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
                dp[i + 1][min(j + as[i], x)][min(k + bs[i], y)] = min(dp[i + 1][min(j + as[i], x)][min(k + bs[i], y)], dp[i][j][k] + 1);
            }
        }
    }

    cout << (dp[n][x][y] == INF ? -1 : dp[n][x][y]) << endl;

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