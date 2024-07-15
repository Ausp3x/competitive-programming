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
    int n, x;
    cin >> n >> x;
    vector<lng> A(n);
    for (lng &a : A)
        cin >> a;
    
    lng ans = 1;
    map<lng, bool> m;
    for (int a : A) {
        if (x % a != 0 || a == 1) {
            continue;
        }

        bool is_good = true;
        for (auto [k, v] : m) {
            if (k * a == x) {
                is_good = false;
                break;
            }
        }

        if (!is_good) {
            ans++;
            m.clear();
            m[a] = true;
            continue;
        }

        map<lng, bool> new_m;
        new_m[a] = true;
        for (auto [k, v] : m) {
            new_m[k] = true;
            if (x % (k * a) == 0)
                new_m[k * a] = true;
        }
        m = new_m;
        // cout << a << ' ' << ans << endl;
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
        solve(t);
    }

    return 0;
}