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

void solve() {
    lng x, y, k;
    cin >> x >> y >> k;
    // cout << x << ' ' << y << ' ' << k << endl;

    while (k > 0) {
        int cur = y - x % y;
        if (k < cur) {
            cout << x + k << endl;
            return;
        }

        x += cur;
        k -= cur;

        while (x % y == 0)
            x /= y;

        if (k == 0) {
            cout << x << endl;
            return;
        }

        if (x == 1)
            break;
    }

    // cout << "* " << x << ' ' << k << endl;
    cout << x + k % (y - 1) << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}