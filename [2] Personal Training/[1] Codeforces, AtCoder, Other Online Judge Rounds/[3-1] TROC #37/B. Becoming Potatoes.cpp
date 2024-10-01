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
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> AB(N);
    for (auto &[a, b] : AB)
        cin >> a;
    for (auto &[a, b] : AB)
        cin >> b;

    lng l = 0, r = 10001;
    while (r - l > 1) {
        lng md = (l + r) / 2;

        vector<vector<int>> dp(N + 1, vector<int>(K + 1, INF32));
        dp[0][0] = 0;
        for (int i = 0; i < N; i++) 
            for (int j = 0; j <= K; j++) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + AB[i].se);
                if (j + AB[i].fi <= K)
                    dp[i + 1][j + AB[i].fi] = min(dp[i + 1][j + AB[i].fi], dp[i][j]);
            }

        bool is_possible = false;
        for (int j = 0; j <= K; j++) {
            if (dp[N][j] == INF32)
                continue;

            int slices = (K - j) * md;
            is_possible |= dp[N][j] <= slices;
        }

        if (is_possible)
            r = md;
        else
            l = md;
    }

    cout << r << endl;

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