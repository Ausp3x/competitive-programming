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

void solve() {
    int n;
    cin >> n;
    vector<lng> a_prfs(n);
    for (lng &a : a_prfs) {
        cin >> a;
    }

    vector<lng> a_prf_maxs(n);
    a_prf_maxs[0] = a_prfs[0];
    for (int i = 1; i < n; i++) {
        a_prfs[i] += a_prfs[i - 1];
        a_prf_maxs[i] = max(a_prfs[i], a_prf_maxs[i - 1]);
    }

    lng ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, cur + a_prf_maxs[i]);
        cur += a_prfs[i];
    }

    cout << ans << '\n';

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