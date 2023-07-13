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
    int n;
    cin >> n;
    vector<lng> V(n);
    for (lng &v : V) {
        cin >> v;
    }

    lng ans_sum = 0;
    for (int i = 0; i < n; i++) {
        lng ans = 0, cur = 0;
        for (int j = i; j < n; j++) {
            cur = min(V[j], cur + V[j]);
            ans = min(ans, cur);
            (ans_sum += ans) %= MOD;
        }
    }

    cout << (ans_sum % MOD + MOD) % MOD << endl;

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