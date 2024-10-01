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
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    int l = 0, r = 1000000001;
    while (r - l > 1) {
        int md = (l + r) / 2;

        vector<int> B(n);
        for (int i = 0; i < n; i++)
            B[i] = A[i] >= md ? 1 : -1;

        vector<int> dp(n);
        dp[0] = B[0];
        for (int i = 1; i < n; i++) 
            if (i % k == 0) {
                dp[i] = max(dp[i - k], B[i]);
            } else {
                dp[i] = dp[i - 1] + B[i];
                if (i >= k)
                    dp[i] = max(dp[i], dp[i - k]);
            }

        if (dp[n - 1] > 0)
            l = md;
        else
            r = md;
    }

    cout << l << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}