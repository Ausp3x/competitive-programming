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
    bool all_1 = true;
    vector<lng> A(n);
    for (lng &a : A) {
        cin >> a;
        all_1 &= a == 1;
    }

    if (all_1) {
        cout << 0 << endl;
        return;
    }

    bool is_sorted = true;
    for (int i = 1; i < n; i++)
        if (A[i] < A[i - 1]) {
            is_sorted = false;
            break;
        }

    if (is_sorted) {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i < n; i++)
        if (A[i] == 1 && A[i - 1] > 1) {
            cout << -1 << endl;
            return;
        }

    lng cur = 0, ans = 0;
    for (int i = 1; i < n; i++) {
        cur = max<lng>(0, ceil(cur + log2(log2(double(A[i - 1])) / log2(double(A[i])))));
        ans += cur;
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
        solve();
    }

    return 0;
}