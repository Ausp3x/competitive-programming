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
    int n;
    cin >> n;
    lng sum = 0;
    vector<int> as(n);
    for (int &a : as) {
        cin >> a;
        sum += a;
    }

    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cur += as[i] == sum - as[i];
    }
    ans = max(ans, cur);

    for (int i = 0; i < n; i++) {
        map<lng, int> cnts;
        cnts[sum - 2 * as[i]]++;
        for (int j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }

            cnts[2 * as[j] - sum]++;
        }

        for (auto &[k, v] : cnts) {
            ans = max(ans, v);
        }
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