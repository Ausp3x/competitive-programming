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

vector<lng> facts(200001);
vector<lng> invs(200001), inv_facts(200001);

lng choose(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }

    return facts[n] * inv_facts[k] % MOD * inv_facts[n - k] % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<int> as(n); 
    for (int &a : as) {
        cin >> a;
    }

    lng ans = 0;
    if (n % 4 == 0) {
        for (int i = 0; i < n; i += 2) {
            (ans += choose(n / 2 - 1, i / 2) * as[i]) %= MOD;
            (ans += -choose(n / 2 - 1, i / 2) * as[i + 1]) %= MOD;
            (ans += MOD) %= MOD;
        }

    } else if (n % 4 == 1) {
        for (int i = 0; i < n; i += 2) {
            (ans += choose(n / 2, i / 2) * as[i]) %= MOD;
        }
    } else if (n % 4 == 2) {
        for (int i = 0; i < n; i += 2) {
            (ans += choose(n / 2 - 1, i / 2) * as[i]) %= MOD;
            (ans += choose(n / 2 - 1, i / 2) * as[i + 1]) %= MOD;
        }
    } else if (n % 4 == 3) {
        for (int i = 0; i < n; i += 2) {
            (ans += (choose(n / 2 - 1, i / 2) - choose(n / 2 - 1, i / 2 - 1)) * as[i]) %= MOD;
            (ans += MOD) %= MOD;
        }
        for (int i = 1; i < n; i += 2) {
            (ans += 2 * choose(n / 2 - 1, i / 2) * as[i]) %= MOD;
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

    facts[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        (facts[i] = facts[i - 1] * i) %= MOD;
    }

    invs[0] = 1;
    invs[1] = 1;
    inv_facts[0] = 1;
    inv_facts[1] = 1;
    for (int i = 2; i <= 200000; i++) {
        (invs[i] = invs[MOD % i] * (MOD - MOD / i)) %= MOD;
        (inv_facts[i] = inv_facts[i - 1] * invs[i]) %= MOD;
    }

    int t = 1;
    // cin >> t;
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