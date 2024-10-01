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
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    if (n == 2) {
        cout << 1 << ' ' << 0 << endl;
        return;
    }

    if (n == 3) {
        cout << 1 << ' ' << 0 << ' ' << 2 << endl;
        return;
    }

    int n_sq = 0;
    while (n_sq * n_sq < n - 1)
        n_sq++;

    int rem = n - 1, lst = n - 1;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        if (n_sq * n_sq - i > rem) {
            rem = n_sq * n_sq - lst - 1;
            lst = i;
            while (n_sq > 0 && (n_sq - 1) * (n_sq - 1) >= i)
                n_sq--;
        }

        ans[i] = n_sq * n_sq - i;
    }

    for (int x : ans)
        cout << x << ' ';
    cout << endl;

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