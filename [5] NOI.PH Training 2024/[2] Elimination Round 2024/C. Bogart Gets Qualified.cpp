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
    int E, N;
    cin >> E >> N;
    vector<int> ns(N);
    for (int &n : ns) {
        cin >> n;
    }
    // ith problem, up to jth subtask
    vector<vector<lng>> es(N);
    for (int i = 0; i < N; i++) {
        es[i].resize(ns[i]);
        for (int j = 0; j < ns[i]; j++) {
            cin >> es[i][j];
        }
    }
    vector<vector<lng>> ps(N);
    for (int i = 0; i < N; i++) {
        ps[i].resize(ns[i]);
        for (int j = 0; j < ns[i]; j++) {
            cin >> ps[i][j];
            if (j > 0) {
                ps[i][j] += ps[i][j - 1];
            }
        }
    }

    if (N == 1) {
        int ans = 0;
        for (int j = 0; j < ns[0]; j++) {
            if (es[0][j] <= E) {
                ans = j + 1;
            }
        }
        cout << ans << endl;

        return;
    }

    // maximum points obtainable solving up to the ith problem with j effort, 
    // current subtask solved
    vector<vector<pair<lng, int>>> dp(N + 1, vector<pair<lng, int>>(E + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= E; j++) {
            dp[i][j].first = dp[i - 1][j].first; 
            for (int k = 0; k < ns[i - 1]; k++) {
                if (es[i - 1][k] > j) {
                    break;
                }

                if (dp[i - 1][j - es[i - 1][k]].first + ps[i - 1][k] > dp[i][j].first) {
                    dp[i][j].first = dp[i - 1][j - es[i - 1][k]].first + ps[i - 1][k];
                    dp[i][j].second = k + 1;
                }
            }
        }
    }

    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= E; j++) {
    //         cout << dp[i][j].second << ' ';
    //     }
    //     cout << endl;
    // }

    int effort_left = E;
    vector<int> ans(N);
    for (int i = N; i > 0; i--) {
        ans[i - 1] = dp[i][effort_left].second;
        if (dp[i][effort_left].second > 0) {
            effort_left -= es[i - 1][dp[i][effort_left].second - 1];
        }
    }
    
    for (int a : ans) {
        cout << a << ' ';
    }
    cout << endl;

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