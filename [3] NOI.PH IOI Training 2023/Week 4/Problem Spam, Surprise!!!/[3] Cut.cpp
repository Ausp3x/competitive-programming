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
    int n, c;
    cin >> n >> c;
    vector<lng> ls(n);
    for (lng &l : ls) {
        cin >> l;
    }

    int l = 1, r = 1 << 30;
    while (l < r) {
        int md = (l + r) / 2;
        lng cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (ls[i] - 1) / md;
        }

        if (cnt > c) {
            l = md + 1;
        } else {
            r = md;
        }
    }

    cout << l << endl;
    
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