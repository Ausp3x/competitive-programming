// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

#define ONLINE_JUDGE
// #define DEBUG

void solve() {
    int m, n;
    cin >> m >> n;

    vector<int> truthfulness(n);
    for (int &x : truthfulness) {
        cout << 1 << endl;
        cin >> x;

        if (x == 0) {
            return;
        }
    }

    int l = 1, r = m;
    for (int i = 0; i < 60 - n; i++) {        
        int md = (l + r) / 2;
        cout << md << endl;

        int x;
        cin >> x;
        x *= truthfulness[i % n];

        if (x == 0) {
            return;
        }

        if (x < 0) {
            r = md - 1;
        } else {
            l = md + 1;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifdef DEBUG
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef DEBUG
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef DEBUG
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}