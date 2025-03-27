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
    string s;
    cin >> s;

    bool chk = false;
    string ans;
    for (int i = 0; i < s.size(); i++) {
        ans += s[i];
        if (i + 1 < s.size())
            if (s[i] == s[i + 1] && !chk) {
                ans += char('a' + (((s[i] - 'a') + 1) % 26));
                chk = true;
            }
    }
    if (ans.size() == s.size()) 
        ans += char('a' + (((s.back() - 'a') + 1) % 26));

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