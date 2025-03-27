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
    int q;
    lng p2, p3, v1, v2, v3;
    cin >> q >> p2 >> p3 >> v1 >> v2 >> v3;

    while (q--) {
        lng c;
        cin >> c;
        
        lng ans = 0;
        for (lng i = 0; i <= c; i++) {
            for (lng j = 0; i + j <= c; j += p2) {
                lng k = c - i - j;
                if (k < 0) {
                    break;
                }

                ans = max(ans, i * v1 + j / p2 * v2 + k / p3 * v3);
            }
        }

        cout << ans << endl;
    }

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