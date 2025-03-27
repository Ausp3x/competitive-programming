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

void solve(int t) {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int g, h, i, j, k, l;
    cin >> g >> h >> i >> j >> k >> l;

    bool chk1 = (a < g && g < d) || (a < j && j < d) || (g <= a && d <= j); 
    bool chk2 = (b < h && h < e) || (b < k && k < e) || (h <= b && e <= k); 
    bool chk3 = (c < i && i < f) || (c < l && l < f) || (i <= c && f <= l); 

    if (chk1 && chk2 && chk3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}