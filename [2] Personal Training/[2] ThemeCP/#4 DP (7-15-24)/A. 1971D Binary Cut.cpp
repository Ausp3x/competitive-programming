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
    string s;
    cin >> s;

    int n = s.size();
    if (n == 1) {
        cout << n << endl;
        return;
    }

    int ans = INF32;
    for (int i = 0; i + 1 < n; i++) {
        int l = -1, r = -1;
        if (s[i] == '0' && s[i + 1] == '1') {
            l = i, r = i + 1;
        }

        if (l == -1)
            continue;

        while (l - 1 >= 0)
            if (s[l - 1] == '0')
                l--;
            else
                break;

        while (r + 1 < n)
            if (s[r + 1] == '1')
                r++;
            else
                break;

        // cout << l << ' ' << r << ' ';

        int cur = 1;
        char prv = 'X';
        for (int j = 0; j < l; j++) {
            if (s[j] != prv)
                cur++;

            prv = s[j];
        }

        prv = 'X';
        for (int j = n - 1; j > r; j--) {
            if (s[j] != prv)
                cur++;

            prv = s[j];
        }

        // cout << cur << endl;

        ans = min(ans, cur);
    }

    if (ans == INF32)
        cout << 1 + (s[0] != s[n - 1]) << endl;
    else 
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