// 人外有人，天外有天
// author: Ausp3x

// #pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int cur = 0;
    lng ans = 0;
    map<int, lng> lens;
    lens[0] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            cur--;
        else
            cur++;
        
        ans += lens[cur] * (n - i);
        ans %= MOD;

        lens[cur] += i + 2;
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}