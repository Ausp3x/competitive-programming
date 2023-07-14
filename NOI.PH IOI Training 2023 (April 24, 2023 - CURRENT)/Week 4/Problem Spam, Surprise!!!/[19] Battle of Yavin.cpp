// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define TROUBLESHOOT

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> cs(n), vs(n);
    for (int i = 0; i < n; i++) {
        cin >> vs[i] >> cs[i];
    }

    vector<int> dp(d + 1);
    for (int i = 0; i <= d; i++) {
        for (int j = 0; j < n; j++) {
            if (cs[j] <= i) {
                dp[i] = max(dp[i], dp[i - cs[j]] + vs[j]);
            }
        }
    }

    cout << dp[d] << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef TROUBLESHOOT
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef TROUBLESHOOT
    // testing code
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

#ifdef TROUBLESHOOT
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}