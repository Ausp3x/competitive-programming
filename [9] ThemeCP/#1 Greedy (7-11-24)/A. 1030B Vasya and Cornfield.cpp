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
    int n, d;
    cin >> n >> d;
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        
        if (x <= d && y < d - x) {
            // cout << 1 << ' ';
            cout << "NO" << endl;
            continue;
        }

        if (x <= n - d && y > d + x) {
            // cout << 2 << ' ';
            cout << "NO" << endl;
            continue;
        }

        if (x >= d && y < x - d) {
            // cout << 3 << ' ';
            cout << "NO" << endl;
            continue;
        }

        if (x >= n - d && y > 2 * n - d - x) {
            // cout << 4 << ' ';
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }
    
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