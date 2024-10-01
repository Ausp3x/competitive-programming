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
    for (int &a : A) {
        cin >> a;
        a--;
    }

    bool is_all_same = true;
    bool is_all_less_than_2 = A[n - 1] < 2;
    for (int i = 0; i + 1 < n; i++) {
        is_all_same &= A[i] == A[i + 1];
        is_all_less_than_2 &= A[i] < 2;
    }

    // cout << is_all_same << endl;
    // cout << is_all_less_than_2 << endl;

    if (is_all_same) {
        cout << n - n / (A[0] + 1) << endl;
        return;
    }

    if (is_all_less_than_2) {
        int cur = 0, ans = (A[0] != cur);
        for (int i = 1; i < n; i++) {
            if (cur == 0) {
                cur = A[i];
            } else if (cur == 1) {
                cur = 0;
            }

            ans += A[i] != cur;
        }

        cout << ans << endl;
        return;
    }

    if (n <= 3000) {
        vector<vector<int>> dp(n, vector<int>(n, INF32));
        dp[0][0] = A[0] != 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++)
                dp[i][0] = min(dp[i][0], dp[i - 1][j] + (A[i] != 0));
            for (int j = 1; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (A[i] != j));
        }

        int ans = INF32;
        for (int j = 0; j < n; j++)
            ans = min(ans, dp[n - 1][j]);

        cout << ans << endl;
        return;
    }

    map<int, int> cnts;
    vector<tuple<int, int, int>> intervals;
    for (int i = 0; i < n; i++) {
        if (i - A[i] < 0)
            continue;

        intervals.pb({i, -i + A[i], cnts[i - A[i]] + 1});
        cnts[i - A[i]]++;
    }

    sort(intervals.begin(), intervals.end());

    // for (auto [r, l, v] : intervals)
    //     cout << abs(l) + 1 << ' ' << r + 1 << ' ' << v << endl;

    int j = 0;
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        while (j < intervals.size()) {
            auto [r, l, v] = intervals[j];
            r++;
            l = abs(l) + 1;
            if (r != i) 
                break;
            
            j++;
            dp[r] = max(dp[r], dp[l - 1] + v);
        }
    }

    // for (int x : dp)
    //     cout << x << ' ';
    // cout << endl;

    cout << n - dp[n] << endl;

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