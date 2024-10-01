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
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    vector<vector<int>> a_prf(n + 1, vector<int>(26));
    vector<vector<int>> b_prf(n + 1, vector<int>(26));
    for (int i = 1; i <= n; i++) {
        a_prf[i][a[i - 1] - 'a']++;
        b_prf[i][b[i - 1] - 'a']++;
        for (int j = 0; j < 26; j++) {
            a_prf[i][j] += a_prf[i - 1][j];
            b_prf[i][j] += b_prf[i - 1][j];
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = 0;
        for (int j = 0; j < 26; j++) {
            ans += abs((a_prf[r][j] - a_prf[l - 1][j]) - (b_prf[r][j] - b_prf[l - 1][j]));
        }

        cout << ans / 2 << endl;
    }
     
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