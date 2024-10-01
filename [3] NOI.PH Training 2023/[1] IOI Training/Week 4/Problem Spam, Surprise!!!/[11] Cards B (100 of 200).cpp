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
    int n, l;
    cin >> n >> l;
    vector<lng> v_psms(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v_psms[i];
        v_psms[i] += v_psms[i - 1];
    }

    lng ans_num = 0, ans_den = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (j - i + 1 < l) {
                continue;
            }
            
            lng num = v_psms[j] - v_psms[i - 1];
            lng den = j - i + 1;
            if (__int128(num) * ans_den > __int128(ans_num) * den) {
                lng gcd = __gcd(num, den);
                ans_num = num / gcd;
                ans_den = den / gcd;
            }
        }
    }

    cout << ans_num << '/' << ans_den << endl;

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