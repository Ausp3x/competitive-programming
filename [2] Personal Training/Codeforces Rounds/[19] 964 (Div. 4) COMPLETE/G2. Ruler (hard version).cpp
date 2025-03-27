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
    int ans = 0;
    for (int i = 729; i > 0; i /= 3) {
        if (ans + i > 999)
            continue;

        if (ans + 2 * i > 999) {
            cout << "? " << ans + i << ' ' << ans + i << endl;
            int res;
            cin >> res;
            
            if (res == (ans + i) * (ans + i))
                ans += i;
            continue;
        }

        cout << "? " << ans + i << ' ' << ans + 2 * i << endl;
        int res;
        cin >> res;
        
        if (res == (ans + i) * (ans + 2 * i))
            ans += 2 * i;
        else if (res == (ans + i) * (ans + 2 * i + 1))
            ans += i;
    }

    cout << "! " << ans + 1 << endl;
    
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