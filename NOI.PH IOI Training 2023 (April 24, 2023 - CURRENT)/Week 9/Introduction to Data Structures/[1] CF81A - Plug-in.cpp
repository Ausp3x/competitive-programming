// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

void solve() {
    char c;
    stack<char> s;
    while (cin >> c) {
        if (!s.empty()) {
            if (c == s.top()) {
                s.pop();
            
                continue;
            }
        }

        s.push(c);
    }

    string ans;
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }

    reverse(ans.begin(), ans.end());

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