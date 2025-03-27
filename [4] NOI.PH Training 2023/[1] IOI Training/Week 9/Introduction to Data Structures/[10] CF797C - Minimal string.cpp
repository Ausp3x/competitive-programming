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

    map<char, int> chr_cnts;
    for (char c : s) {
        chr_cnts[c]++;
    }

    stack<char> t;
    string u;
    for (char c : s) {
        while (!t.empty()) {
            if (t.top() <= chr_cnts.begin()->first) {
                u += t.top();
                t.pop();
            } else {
                break;
            }
        }

        t.push(c);
        chr_cnts[c]--;

        while (!chr_cnts.empty()) {
            if (chr_cnts.begin()->second == 0) {
                chr_cnts.erase(chr_cnts.begin());
            } else {
                break;
            }
        }
    }

    while (!t.empty()) {
        u += t.top();
        t.pop();
    }

    cout << u << endl;
    
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