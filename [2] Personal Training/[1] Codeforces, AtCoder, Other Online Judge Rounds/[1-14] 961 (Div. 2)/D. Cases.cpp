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
    int n, c, k;
    cin >> n >> c >> k;
    string s;
    cin >> s;

    vector<bool> is_msk(1 << c);
    vector<int> cnts(c);
    is_msk[1 << (s.back() - 'A')] = true;
    for (int i = 0; i < k; i++)
        cnts[s[i] - 'A']++;
    for (int i = k - 1; i < n; i++) {
        if (i >= k) {
            cnts[s[i] - 'A']++;
            cnts[s[i - k] - 'A']--;
        }

        int cur_msk = 0;
        for (int j = 0; j < c; j++)
            if (cnts[j] > 0)
                cur_msk |= 1 << j;

        is_msk[cur_msk] = true;
    }

    // for (int msk = 0; msk < (1 << c); msk++)
    //     if (is_msk[msk])
    //         cout << msk << ' ';
    // cout << endl;

    vector<int> is_bad_msk(1 << c);
    for (int msk = 0; msk < (1 << c); msk++)
        if (is_msk[msk])
            is_bad_msk[((1 << c) - 1) ^ msk] = true;

    // for (int msk = 0; msk < (1 << c); msk++)
    //     if (is_bad_msk[msk])
    //         cout << msk << ' ';
    // cout << endl;

    for (int msk = (1 << c) - 1; msk >= 0; msk--)        
        for (int i = 0; i < c; i++)
            is_bad_msk[msk] |= is_bad_msk[msk | (1 << i)];

    int ans = c;
    for (int msk = 0; msk < (1 << c); msk++)
        if (!is_bad_msk[msk])
            ans = min(ans, __builtin_popcount(msk));

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