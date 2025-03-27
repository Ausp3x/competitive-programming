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

int N = 1000000;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> as(n);
    for (int &a : as)
        cin >> a;
    vector<int> bs(n);
    for (int &b : bs)
        cin >> b;
    vector<int> cs(m);
    for (int &c : cs)
        cin >> c;

    vector<pair<int, int>> ds(n);
    for (int i = 0; i < n; i++)
        ds[i] = {as[i], as[i] - bs[i]};
    
    sort(ds.begin(), ds.end());

    // for (auto [x, y] : ds)
    //     cout << x << ' ' << y << endl;

    int j = -1, min_d = INF32;
    vector<int> dp(N + 1, 0);
    dp[0] = 0;
    for (int i = 0; i <= N; i++) {
        while (j < n - 1)
            if (i >= ds[j + 1].first) {
                j++;
                min_d = min(min_d, ds[j].second);
            } else
                break;

        if (j == -1)
            continue;

        dp[i] = dp[i - min_d] + 2;    
    }

    // for (int i = 0; i <= 20; i++)
    //     cout << dp[i] << ' ';
    // cout << endl;

    lng ans = 0;
    for (int c : cs) {
        if (c <= N)
            ans += dp[c];
        else {
            lng cur = (c - N + min_d - 1) / min_d;
            ans += 2 * cur;
            ans += dp[c - min_d * cur];
        }
    }

    cout << ans << endl;
    
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