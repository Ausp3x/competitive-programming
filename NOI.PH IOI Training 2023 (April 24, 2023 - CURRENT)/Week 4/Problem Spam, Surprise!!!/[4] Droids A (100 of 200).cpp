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
    vector<lng> values(2 * n + 1);
    for (int i = n; i > 0; i--) {
        cin >> values[i];
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        cin >> values[i];
    }

    for (int i = 1; i <= 2 * n; i++) {
        values[i] += values[i - 1];
    }

    lng ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        lng cur = -1e18;
        for (int j = 1; j + i - 1 <= 2 * n; j++) {
            if (j > n + 1|| j + i - 1 < n) {
                continue;
            }

            cur = max(cur, values[j + i - 1] - values[j - 1]);
        }

        ans ^= cur;
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