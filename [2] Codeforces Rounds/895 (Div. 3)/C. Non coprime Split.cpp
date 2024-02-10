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
    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0 && min(j, i - j) > 0) {
                cout << j << ' ' << i - j << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
    
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