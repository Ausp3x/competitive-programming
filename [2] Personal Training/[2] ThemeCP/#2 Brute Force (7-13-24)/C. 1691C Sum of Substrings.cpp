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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (s[n - 1] == '0') {
        int ii = INF32;
        for (int i = n - 2; i >= 0; i--) {
            if (n - i - 1 > k)
                break;
            
            if (s[i] == '1') {
                ii = i;
                break;
            }
        }

        while (ii < n - 1) {
            swap(s[ii], s[ii + 1]);
            k--;
            ii++;
        }
    }

    if (s[0] == '0') {
        int ii = -INF32;
        for (int i = 1; i < n - 1; i++) {
            if (i > k)
                break;
            
            if (s[i] == '1') {
                ii = i;
                break;
            }
        }

        while (ii > 0) {
            swap(s[ii], s[ii - 1]);
            k--;
            ii--;
        }
    }

    // cout << s << endl;

    int ans = 10 * (s[0] - '0') + (s[n - 1] - '0');
    for (int i = 1; i < n - 1; i++)
        ans += 11 * (s[i] - '0');

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