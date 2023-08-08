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

    int ans = 0;
    for (lng i = 1; i <= n; i++) {
        int ii = i;
        map<int, int> prime_cnts;
        for (int j = 2; j * j <= ii; j++) {
            while (ii % j == 0) {
                prime_cnts[j]++;
                ii /= j;
            }
        }
        if (ii > 1) {
            prime_cnts[ii]++;
        }
    
        int d = 1;
        for (auto &[p, cnt] : prime_cnts) {
            d *= pow(p, (cnt + 1) / 2);
        }

        int l = sqrt(i - 1), r = sqrt(i * n);
        ans += r / d - l / d;
        // cout << i << ' ' << l << ' ' << r << ' ' << d << ' ' << r / d - l / d << ' ' << ans << endl;
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