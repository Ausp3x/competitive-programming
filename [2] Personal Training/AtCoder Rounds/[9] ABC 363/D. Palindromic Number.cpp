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
    lng N;
    cin >> N;

    if (N <= 10) {
        cout << N - 1 << endl;
        return;
    }
    
    N--;

    int len = 1;
    lng cur = 9;
    while (cur <= N) {
        len++;
        N -= cur;
        
        if (len % 2 == 1)
            cur *= 10;

        // cout << len << ' ' << cur << endl;
    }

    // cout << N << endl;
    // cout << len << endl;

    N--;
    cur /= 9;

    string ans(len, '0');
    ans[0] = '1';
    ans[len - 1] = '1';
    for (int i = 0; i < (len + 1) / 2; i++) {
        // cout << N << ' ' << N / cur << endl;
        
        int r = N / cur;
        N -= r * cur;
        cur /= 10;

        ans[i] += r;
        if (len - i - 1 != i)
            ans[len - i - 1] += r;
    }

    cout << ans << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}