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
    string s, t;
    cin >> s >> t;

    int s_len = s.size();
    for (int c = 1; c < s_len; c++)
        for (int w = c; w < s_len; w++) {
            string cur;
            for (int i = c - 1; i < s_len; i += w) {
                cur += s[i];
            }

            if (cur == t) {
                cout << "Yes" << endl;
                return;
            }
        }

    cout << "No" << endl; 

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