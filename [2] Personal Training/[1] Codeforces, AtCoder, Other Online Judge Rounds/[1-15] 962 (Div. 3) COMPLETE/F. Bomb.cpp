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
    int n, k;
    cin >> n >> k;
    vector<lng> A(n);
    for (lng &a : A)
        cin >> a;
    vector<lng> B(n);
    for (lng &b : B)
        cin >> b;
    
    int l = 0, r = 1000000001;
    lng ans_used_k = 0;
    lng ans = 0;
    while (r - l > 1) {
        int m = (l + r) / 2;

        lng cur_used_k = 0;
        lng cur = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] < m)
                continue;

            int d = (A[i] - m) / B[i] + 1;
            cur_used_k += d;
            cur += 1ll * d * (2 * A[i] - (d - 1) * B[i]) / 2;
        }

        if (cur_used_k <= k) {
            r = m;
            ans_used_k = cur_used_k;
            ans = cur;
        } else {
            l = m;
        }
    }

    k -= ans_used_k;
    
    cout << ans + (1ll * k * l) << endl;

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