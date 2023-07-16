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
    int n, k;
    cin >> n >> k;
    vector<lng> bs(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> bs[i];
    }
    vector<lng> ds(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ds[i];
    }

    vector<vector<lng>> dp(n + 1, vector<lng>(k + 1, -1e18));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (dp[i - 1][j - 1] != -1e18) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + bs[i]);
            }
            if (j >= 2) {
                if (dp[i - 1][j - 2] != -1e18) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 2] + bs[i] + ds[i]);
                }
            }
        }
    }

    cout << dp[n][k] << endl;

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
    cin >> t;
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