// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    string a, b;
    cin >> a >> b;

    int max_cnt = 0;
    for (int i = 0; i < b.size(); i++) {
        int ii = i, cnt = 0;
        for (char x : a)
            if (x == b[ii]) {
                // cout << x;
                ii++;
                cnt++;
            }
        // cout << endl;

        max_cnt = max(max_cnt, cnt);
    }

    cout << a.size() + b.size() - max_cnt << endl;

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