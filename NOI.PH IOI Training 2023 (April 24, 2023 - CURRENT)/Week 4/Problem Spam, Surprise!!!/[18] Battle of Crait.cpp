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
    vector<int> dp(10001, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int v, c;
        cin >> v >> c;
        
        for (int j = 0; j + v <= 10000; j++) {
            dp[j + v] = min(dp[j + v], dp[j] + c);
        }
    }

    int ans = 1e9;
    for (int i = d; i <= 10000; i++) {
        ans = min(ans, dp[i]);
    }
    
    cout << ans << endl;

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