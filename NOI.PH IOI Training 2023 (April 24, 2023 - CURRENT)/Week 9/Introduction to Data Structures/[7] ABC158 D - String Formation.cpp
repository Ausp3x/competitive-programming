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
    string s;
    cin >> s;
    int q;
    cin >> q;

    deque<char> dq;
    for (auto &c : s) {
        dq.push_back(c);
    }

    bool is_reversed = false;
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            is_reversed ^= true;
        } else if (t == 2) {
            int f;
            char c;
            cin >> f >> c;

            if (f == 1) {
                if (is_reversed) {
                    dq.push_back(c);
                } else {
                    dq.push_front(c);
                }
            } else if (f == 2) {
                if (is_reversed) {
                    dq.push_front(c);
                } else {
                    dq.push_back(c);
                }
            }
        }
    }

    if (is_reversed) {
        while (!dq.empty()) {
            cout << dq.back();
            dq.pop_back();
        }
        cout << endl;
    } else {
        while (!dq.empty()) {
            cout << dq.front();
            dq.pop_front();
        }
        cout << endl;
    }
    
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