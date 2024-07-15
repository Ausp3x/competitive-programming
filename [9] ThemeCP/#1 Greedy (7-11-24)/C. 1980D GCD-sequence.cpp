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

void solve(int t) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;
    
    vector<int> B(n, -1);
    for (int i = 1; i < n; i++)
        B[i] = __gcd(A[i - 1], A[i]);
    
    vector<int> C(n, -1);
    for (int i = 2; i < n; i++)
        C[i] = __gcd(A[i - 2], A[i]);


    vector<vector<int>> dp(2, vector<int>(n, INF32));
    dp[0][0] = 0;
    dp[1][1] = 0;
    for (int i = 1; i < n; i++) {
        if (B[i] >= dp[0][i - 1])
            dp[0][i] = B[i];

        if (i > 1) {
            if (B[i] >= dp[1][i - 1])
                dp[1][i] = B[i];

            if (C[i] >= dp[0][i - 2])
                dp[1][i] = min(dp[1][i], C[i]);
        }
    }

    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < n; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << endl;
    // }

    if (dp[0][n - 2] == INF32 && dp[1][n - 1] == INF32) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}