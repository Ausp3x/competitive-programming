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
    int l;
    cin >> l;

    lng ans = 0;
    stack<pair<int, lng>> muls;
    while (l--) {
        string s;
        cin >> s;

        if (s == "add") {
            if (muls.empty()) {
                ans++;
            } else {
                muls.top().second++;
            }
        } else if (s == "for") {
            int x;
            cin >> x;

            muls.push({x, 0});
        } else if (s == "end") {
            lng cur = muls.top().first * muls.top().second;
            muls.pop();

            if (cur > UINT_MAX) {
                cout << "OVERFLOW!!!" << endl;
                
                return;
            }

            if (muls.empty()) {
                ans += cur;
            } else {
                muls.top().second += cur;
            }
        }

        if (ans > UINT_MAX) {
            cout << "OVERFLOW!!!" << endl;
            
            return;
        }
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