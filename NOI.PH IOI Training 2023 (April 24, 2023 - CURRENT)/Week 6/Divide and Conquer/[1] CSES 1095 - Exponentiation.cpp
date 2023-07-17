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

int const MOD = 1e9 + 7;

lng fast_mod_exp(lng a, lng b) {    
    if (b == 0) {
        return 1;
    }

    if (a == 0) {
        return 0;
    }
    
    lng res = fast_mod_exp(a, b / 2);
    (res *= res) %= MOD;
    if (b % 2 == 1) {
        (res *= a) %= MOD;
    }

    return res;
}

void solve() {
    int a, b;
    cin >> a >> b;

    cout << fast_mod_exp(a, b) << endl;

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