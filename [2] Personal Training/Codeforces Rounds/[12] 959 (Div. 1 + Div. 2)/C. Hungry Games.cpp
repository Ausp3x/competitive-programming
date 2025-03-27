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
    int n;
    lng x;
    cin >> n >> x;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    vector<lng> A_psum(n + 1);
    for (int i = 1; i <= n; i++) {
        A_psum[i] = A[i];
        A_psum[i] += A_psum[i - 1];
    }

    // for (lng x : A_psum)
    //     cout << x << ' ';
    // cout << endl;
    
    int j = 1;
    vector<pair<int, int>> ranges;
    for (int i = 1; i <= n; i++) {
        while (A_psum[j] - A_psum[i - 1] <= x && j < n) {
            j++;
        }

        if (A_psum[j] - A_psum[i - 1] <= x)
            continue;

        ranges.push_back({i, j});
    }

    // for (auto [x, y] : ranges) {
    //     cout << x << ' ' << y << endl;
    // }

    vector<lng> dp(n + 1);
    for (auto [x, y] : ranges) {
        dp[y] += dp[x - 1] + 1;
    }
    
    lng dp_sum = 0;
    for (int i = 1; i <= n; i++)
        dp_sum += dp[i];

    cout << 1ll * n * (n + 1) / 2 - dp_sum << endl;
    

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