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
    vector<deque<lng>> A(2);
    for (int i = 0; i < n; i++) {
        lng a;
        cin >> a;

        A[a % 2].pb(a);
    }

    if (A[0].size() == n || A[1].size() == n) {
        cout << 0 << endl;
        return;
    }

    sort(A[0].begin(), A[0].end());
    sort(A[1].begin(), A[1].end());

    int ans = 0;
    lng largest_odd = A[1].back();
    while (!A[0].empty()) {
        if (largest_odd > A[0].front()) {
            ans++;
            largest_odd += A[0].front();
            A[0].pop_front();
        } else {
            ans += 2;
            largest_odd += 2 * A[0].back();
            A[0].pop_back();
        }
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