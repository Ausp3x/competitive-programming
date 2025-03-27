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
    lng h, c, t;
    cin >> h >> c >> t;

    if (t >= h) {
        cout << 1 << endl;
        return;
    }

    if (2 * t <= h + c) {
        cout << 2 << endl;
        return;
    }

    lng d1 = t - c, d2 = h - c;
    
    lng a1 = d1 / (2 * d1 - d2);
    lng a2 = a1 + 1;

    if (abs((2 * a1 - 1) * (2 * a2 - 1) * t - (2 * a2 - 1) * (h * a1 + c * a1 - c)) <= 
        abs((2 * a1 - 1) * (2 * a2 - 1) * t - (2 * a1 - 1) * (h * a2 + c * a2 - c))) 
        cout << 2 * a1 - 1 << endl;
    else
        cout << 2 * a2 - 1 << endl;

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