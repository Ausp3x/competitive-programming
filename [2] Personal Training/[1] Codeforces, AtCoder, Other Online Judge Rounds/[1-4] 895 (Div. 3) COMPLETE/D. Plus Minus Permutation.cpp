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

void solve() {
    lng n, x, y;
    cin >> n >> x >> y;

    if (x == y) {
        cout << 0 << endl;
        return;
    }

    lng lcm = x * y / __gcd(x, y);
    lng n_x = n / x - n / lcm;
    lng n_y = n / y - n / lcm;

    cout << (2 * n - n_x + 1) * n_x / 2 - (n_y + 1) * n_y / 2 << endl;

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