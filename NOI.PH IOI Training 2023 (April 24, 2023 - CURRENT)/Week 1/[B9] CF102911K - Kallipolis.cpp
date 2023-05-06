// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define ONLINE_JUDGE
// #define DEBUG

int gcd(int x, int y) {
    return (y == 0 ? x : gcd(y, x % y));
}

lng lcm(int x, int y) {
    return 1ll * x * y / gcd(x, y);
}

void solve() {
    int n;
    cin >> n;
    int a_max = 0;
    map<int, int> a_idxs;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        a_max = max(a_max, a);
        if (!a_idxs.contains(a)) {
            a_idxs[a] = i;
        }
    }

    lng a_dom = 1;
    for (auto &[a, idx] : a_idxs) {
        a_dom = lcm(a_dom, a);
        
        if (a_dom > a_max) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << (a_idxs[a_dom] ? a_idxs[a_dom] : -1) << '\n';

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