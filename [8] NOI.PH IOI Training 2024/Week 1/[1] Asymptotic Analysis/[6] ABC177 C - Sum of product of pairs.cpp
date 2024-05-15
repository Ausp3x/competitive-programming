// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    lng S_a = 0;
    vector<lng> as(n);
    for (lng &a : as) {
        cin >> a;
        (S_a += a) %= MOD;
    }
    
    lng ans = S_a * S_a % MOD;
    for (lng a : as) {
        ans -= a * a % MOD;
        while (ans < 0) (ans += MOD) %= MOD;
    }
    if (ans % 2 == 1) ans += MOD;
    ans /= 2;

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}