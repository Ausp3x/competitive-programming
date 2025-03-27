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
    vector<int> A(4);
    cin >> A[3] >> A[1] >> A[2] >> A[0];

    if (A[3] == 0) {
        cout << 1 << endl;
        return;
    }

    int ans = A[3];
    ans += 2 * min(A[1], A[2]);
    int cur = abs(A[2] - A[1]) + A[0];
    ans += min(A[3], cur) + (cur > A[3]);
    
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