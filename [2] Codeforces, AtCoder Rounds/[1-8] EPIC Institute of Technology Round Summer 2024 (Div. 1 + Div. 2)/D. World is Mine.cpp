// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve(int t) {
    int n;
    cin >> n;
    vector<int> as(n);
    vector<int> cnts(n + 1);
    for (int &a : as) {
        cin >> a;
        cnts[a]++;
    }

    vector<int> pruned_cnts;
    for (int i = 0; i <= n; i++)
        if (cnts[i] > 0)
            pruned_cnts.push_back(cnts[i]);
    
    if (pruned_cnts.size() == 1) {
        cout << 1 << endl;
        return;
    }

    // for (int x : pruned_cnts)
    //     cout << x << ' ';
    // cout << endl;

    int len = pruned_cnts.size();
    vector<vector<int>> dp(len + 1, vector<int>(n + 1, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++)
            dp[i][j] = dp[i - 1][j - 1];

        for (int j = 0; j <= n - pruned_cnts[i - 1]; j++)
            if (dp[i - 1][j + pruned_cnts[i - 1]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + pruned_cnts[i - 1]] + 1);
    }

    int ans = 0;
    for (int j = 0; j <= n; j++)
        ans = max(ans, dp[len][j]);
    cout << len - ans << endl;

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