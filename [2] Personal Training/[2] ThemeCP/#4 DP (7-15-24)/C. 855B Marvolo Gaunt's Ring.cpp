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
    vector<lng> pqr(3);
    cin >> n >> pqr[0] >> pqr[1] >> pqr[2];
    vector<lng> A(n);
    for (lng &a : A)
        cin >> a;

    vector<vector<lng>> pqrA(3, vector<lng>(n));
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < n; j++)
            pqrA[i][j] = pqr[i] * A[j];

    vector<vector<lng>> dp(3, vector<lng>(n));
    for (int i = 2; i >= 0; i--) {
        dp[i][n - 1] = pqrA[i][n - 1];
        if (i < 2)
            dp[i][n - 1] += dp[i + 1][n - 1];
        for (int j = n - 2; j >= 0; j--) {
            dp[i][j] = pqrA[i][j];
            if (i < 2)
                dp[i][j] += dp[i + 1][j];

            dp[i][j] = max(dp[i][j], dp[i][j + 1]);
        }
    }

    cout << dp[0][0] << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}