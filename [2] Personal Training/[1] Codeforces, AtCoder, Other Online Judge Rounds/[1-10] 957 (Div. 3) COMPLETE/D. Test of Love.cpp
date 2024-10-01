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
    int n, m, k;
    cin >> n >> m >> k;
    string a(n + 2, 'X');
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // cout << a << endl;

    vector<int> dp(n + 2, INF32);
    for (int i = 1; i <= min(m, n + 1); i++)
        if (a[i] != 'C')
            dp[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == INF32)
            continue;

        if (a[i] == 'W') {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            continue;
        }

        for (int j = i + 1; j <= min(i + m, n + 1); j++)
            if (a[i] != 'C')
                dp[j] = min(dp[j], dp[i]);
    }
    
    // for (int x : dp)
    //     cout << x << ' ';
    // cout << endl;

    cout << (dp[n + 1] <= k ? "YES" : "NO") << endl;

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