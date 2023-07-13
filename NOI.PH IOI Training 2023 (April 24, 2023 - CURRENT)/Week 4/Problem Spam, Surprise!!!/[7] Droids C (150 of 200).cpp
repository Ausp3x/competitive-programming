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

int const MOD = 998244353;

void solve() {
    lng n, w, k, f0;
    cin >> n >> w >> k >> f0;
    vector<lng> as(k);
    for (lng &a : as) {
        cin >> a;
    }

    lng f = f0;
    vector<__int128> V(n + 1);
    for (int i = 1; i <= n; i++) {
        (f *= f) %= k;
        V[i] = as[f] + w * i;
    }
    
    __int128 ans = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        cur = min(V[i], cur + V[i]);
        ans = min(ans, cur);
    }

    cout << int((ans % MOD + MOD) % MOD) << "\n";

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