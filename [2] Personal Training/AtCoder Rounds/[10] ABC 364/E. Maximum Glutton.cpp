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
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(X + 1, INF32)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) 
            for (int k = 0; k <= X; k++)
                dp[i + 1][j][k] = dp[i][j][k];
        
        for (int j = 0; j < N; j++) 
            for (int k = 0; k <= X; k++)
                if (k + A[i] <= X)
                    dp[i + 1][j + 1][k + A[i]] = min(dp[i + 1][j + 1][k + A[i]], dp[i][j][k] + B[i]);
    }

    for (int j = N; j >= 0; j--)
        for (int k = 0; k <= X; k++)
            if (dp[N][j][k] <= Y) {
                cout << min(j + 1, N) << endl;
                return;
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