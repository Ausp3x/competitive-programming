// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
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

void solve() {
    int n, x;
    cin >> n >> x;
    
    if (n < 3 || x < 3) {
        cout << 0 << endl;
        return;
    }

    // 111
    lng ans = 1;
    // 11a
    for (lng i = 2; i + 2 <= x; i++)
        if (2 * i + 1 <= n)
            ans += 3;

    // 1aa
    for (lng i = 2; 2 * i + 1 <= x; i++)
        if (i * i + 2 * i <= n)
            ans += 3;
    
    // 1ab
    for (lng i = 2; i * i <= n; i++)
        for (lng j = i + 1; i * j + i + j <= n; j++)
            if (i + j + 1 <= x)
                ans += 6;
    
    // aaa
    for (lng i = 2; 3 * i * i <= n; i++)
        if (3 * i <= x)
            ans++;

    // aab
    for (lng i = 2; i * i <= n; i++)
        for (lng j = i + 1; i * i + 2 * i * j <= n; j++)
            if (2 * i + j <= x)
                ans += 3;
    for (lng i = 2; i * i <= n; i++)
        for (lng j = i + 1; j * j + 2 * i * j <= n; j++)
            if (2 * j + i <= x)
                ans += 3;

    // abc
    for (lng i = 2; i * i <= n; i++)
        for (lng j = i + 1; i * j <= n; j++)
            for (lng k = j + 1; i * j + i * k + j * k <= n; k++)
                if (i + j + k <= x)
                    ans += 6;

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