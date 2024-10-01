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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    
    if (s == t) {
        cout << "YES" << endl;
        return;
    }

    if (s[0] == '1') {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            break;

        if (t[i] == '1') {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

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