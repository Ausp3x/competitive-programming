
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
    int n, q;
    cin >> n >> q;
    vector<lng> l_psms(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> l_psms[i];
        l_psms[i] += l_psms[i - 1];
    }
 
    while (q--) {
        int s;
        cin >> s;
 
        if (n % s == 0) {
            cout << l_psms[n];
            if (q) {
                cout << ' ';
            }

            continue;
        }
 
        if (n / s == 1) {
            cout << l_psms[n] + l_psms[s] - l_psms[n - s];
            if (q) {
                cout << ' ';
            }

            continue;
        }
 
        int quo = n / s;
        lng ans = 1e18;
        for (int i = 0; i <= quo; i++) {
            int l = s * i, r = n - s * (quo - i);
            for (int j = max(r, s); j <= min(l + s, n); j++) {
                ans = min(ans, l_psms[n] + l_psms[j] - l_psms[j - s] - (l_psms[r] - l_psms[l]));
            }
        }
 
        cout << ans;
        if (q) {
            cout << ' ';
        }
    }
    cout << endl;
 
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