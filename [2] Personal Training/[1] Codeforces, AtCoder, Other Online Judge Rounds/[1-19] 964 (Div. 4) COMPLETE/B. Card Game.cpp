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
    vector<int> A(2), B(2);
    cin >> A[0] >> A[1] >> B[0] >> B[1];

    int ans = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            int suneet = 0, slavic = 0;
            
            if (A[i] > B[j]) {
                suneet++;
            } else if (B[j] > A[i]) {
                slavic++;
            }

            if (A[i ^ 1] > B[j ^ 1]) {
                suneet++;
            } else if (B[j ^ 1] > A[i ^ 1]) {
                slavic++;
            }

            if (suneet > slavic)
                ans++;

            // cout << i << ' ' << j << ' ' << suneet << ' ' << slavic << endl;
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