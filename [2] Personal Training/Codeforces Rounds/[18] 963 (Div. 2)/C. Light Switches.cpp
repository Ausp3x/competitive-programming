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
    int A_max = -1;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
        A_max = max(A_max, a);
    }

    int K = 2 * k;
    vector<int> dif_sums(2 * K);
    for (int i = 0; i < n; i++) {
        int rem = A[i] % K;
        dif_sums[rem]++;
        dif_sums[rem + k]--;
    }

    for (int i = 1; i < 2 * K; i++)
        dif_sums[i] += dif_sums[i - 1];

    int ans = A_max;
    for (int i = 0; i < K; i++) {
        int rem = ans % K;
        if (dif_sums[rem] + dif_sums[rem + K] == n) {
            cout << ans << endl;
            return;
        }

        ans++;
    }

    cout << -1 << endl;

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