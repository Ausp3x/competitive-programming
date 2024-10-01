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
    int n;
    cin >> n;
    vector<int> as(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> as[i];
    vector<int> bs(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> bs[i];
    
    
    vector<int> bs1 = bs, ds1(n + 1);
    bs1[1] = 1;
    for (int i = 1; i <= n; i++) {
        ds1[i] = as[i] - bs1[i];
        for (int j = i; j <= n; j += i)
            bs1[j] += ds1[i];
    }

    // for (int x : ds1)
    //     cout << x << ' ';
    // cout << endl;

    vector<int> bs2 = bs, ds2(n + 1);
    bs2[1] = 2;
    for (int i = 1; i <= n; i++) {
        ds2[i] = as[i] - bs2[i];
        for (int j = i; j <= n; j += i)
            bs2[j] += ds2[i];
    }

    // for (int x : ds2)
    //     cout << x << ' ';
    // cout << endl;

    int inc = 0;
    vector<int> dec;
    for (int i = 1; i <= n; i++) {
        int dd = ds2[i] - ds1[i];
        if (dd == 0)
            continue;

        if (dd > 0)
            if (ds1[i] >= 0)
                inc++;
            else
                dec.push_back(abs(ds1[i]));
        else
            if (ds1[i] <= 0)
                inc++;
            else
                dec.push_back(abs(ds1[i]));
    }

    sort(dec.begin(), dec.end(), greater<int>());

    vector<lng> dp(N + 1);
    for (int i = 1; i <= n; i++)
        dp[1] += abs(ds1[i]);
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + inc - dec.size();
        while (!dec.empty())
            if (dec.back() == i - 1) {
                inc++;
                dec.pop_back();
            } else    
                break;
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        cout << dp[x] << endl;
    }

    // int q;
    // cin >> q;
    // while (q--) {
    //     int x;
    //     cin >> x;

    //     lng ans = 0;
    //     vector<int> cbs = bs;
    //     cbs[1] = x;
    //     for (int i = 1; i <= n; i++) {
    //         int cur = as[i] - cbs[i];
    //         cout << cur << ' ';
    //         ans += abs(cur);
    //         for (int j = i; j <= n; j += i)
    //             cbs[j] += cur;
    //     }
    //     cout << endl;

    //     cout << ans << endl;
    // }

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