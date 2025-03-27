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
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    int ans = 0;
    vector<bool> has_changed(n);
    for (int i = 0; i < n; i++) {
        if (A[i] != 2)
            continue;

        if (has_changed[i])
            continue;
        ans++;
        has_changed[i] = true;

        int ii = i;
        while (ii > 0) {
            if (A[ii] == 0)
                break;

            has_changed[--ii] = true;
        }

        ii = i;
        while (ii < n - 1) {
            if (A[ii] == 0)
                break;

            has_changed[++ii] = true;
        }
    }

    // for (bool x : has_changed)
    //     cout << x << ' ';
    // cout << endl;

    for (int i = 0; i < n; i++) {
        if (A[i] != 1)
            continue;

        if (has_changed[i])
            continue;
        ans++;
        has_changed[i] = true;

        int ii = i;
        while (ii < n - 1) {
            if (A[ii + 1] == 0)
                break;

            has_changed[++ii] = true;
        }

        if (i > 0)
            if (!has_changed[i - 1]) {
                has_changed[i - 1] = true;
                continue;
            }
        
        if (ii < n - 1)
            if (!has_changed[ii + 1]) {
                has_changed[ii + 1] = true;
                continue;
            }
    }

    // for (bool x : has_changed)
    //     cout << x << ' ';
    // cout << endl;

    for (int i = 0; i < n; i++) {
        ans += !has_changed[i];
        has_changed[i] = true;
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}