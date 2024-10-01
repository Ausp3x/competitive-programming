// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
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
    int N;
    cin >> N;
    string s;
    cin >> s;

    int cnt = 0;
    lng ans = 1;
    for (int i = 0; i + 2 < N; i++) {
        if (s.substr(i, 3) == "ABA" || s.substr(i, 3) == "BAB") {
            cnt++;
        } else {
            ans *= (cnt + 1) / 2 + 1;
            ans %= MOD;
            cnt = 0;
        }
    }
    ans *= (cnt + 1) / 2 + 1;
    ans %= MOD;

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