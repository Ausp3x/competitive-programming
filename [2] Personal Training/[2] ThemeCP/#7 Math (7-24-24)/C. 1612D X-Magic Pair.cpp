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
    lng a, b, x;
    cin >> a >> b >> x;
    if (a < b)
        swap(a, b);

    if (x > a && x > b) {
        cout << "NO" << endl;
        return;
    }

    lng g = __gcd(a, b);
    if (x % g != 0) {
        cout << "NO" << endl;
        return;
    }

    while (a > 0 && b > 0) {
        if (a % b == x % b && x <= a) {
            cout << "YES" << endl;
            return;
        }
        
        a %= b;
        if (a < b)
            swap(a, b);
    }

    cout << "NO" << endl;
    
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