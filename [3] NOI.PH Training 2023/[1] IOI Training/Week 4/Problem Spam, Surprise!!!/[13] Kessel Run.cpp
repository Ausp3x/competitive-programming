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
    int n, h;
    cin >> n >> h;
    vector<int> cs(n);
    for (int &c : cs) {
        cin >> c;
    }

    sort(cs.begin(), cs.end());

    vector<int> dp(h + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= h; i++) {
        for (int &c : cs) {
            if (c > i) {
                break;
            }

            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    } 

    cout << dp[h] << endl;

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
    // cin >> t;
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