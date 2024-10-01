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
    int n, k;
    cin >> n >> k;
    vector<pair<lng, lng>> droids(n);
    for (auto &[b, d] : droids) {
        cin >> b;
    }
    for (auto &[b, d] : droids) {
        cin >> d;
    }

    lng ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int b_cnt = __builtin_popcount(i), d_cnt = k - b_cnt;
        if (d_cnt < 0 || d_cnt > b_cnt) {
            continue;
        }

        int ii = i;
        lng cur = 0;
        priority_queue<lng> ds;
        for (int j = 0; j < n; j++) {
            if (ii & 1) {
                cur += droids[j].first;
                ds.push(droids[j].second);
            }

            ii >>= 1;
        }

        while (d_cnt--) {
            cur += ds.top();
            ds.pop();
        }

        ans = max(ans, cur);
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