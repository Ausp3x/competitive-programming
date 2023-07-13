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
    lng d;
    cin >> n >> d;
    lng h_max = 0, h_min = 1e18;
    vector<lng> hs(n);
    for (lng &h : hs) {
        cin >> h;
        h_max = max(h_max, h);
        h_min = min(h_min, h);
    }

    lng ans = h_max - h_min, h_max_left = 0, h_min_left = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            h_max_left = max(h_max_left, hs[i - 1]);
            if (i == 1) {
                h_min_left = hs[i - 1];
            } else {
                h_min_left = min(h_min_left, hs[i - 1]);
            }
        }
        
        lng h_max_right = 0, h_min_right = 0;
        for (int j = n - 1; j >= i; j--) {
            if (j < n - 1) {
                h_max_right = max(h_max_right, hs[j + 1]);
                if (j == n - 2) {
                    h_min_right = hs[j + 1];
                } else {
                    h_min_right = min(h_min_right, hs[j + 1]);
                } 
            }
            
            ans = min(ans, d * (j - i + 1) + max(h_max_left, h_max_right) - min(h_min_left, h_min_right));
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