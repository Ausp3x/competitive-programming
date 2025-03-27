// 人外有人，天外有天
// author: Ausp3x

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
    int n, m;
    cin >> n >> m;

    map<pair<int, int>, char> idx_chr;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; i + j <= n; j++) {
            char c;
            cin >> c;

            idx_chr[{j, -(i + j)}] = c;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; i + j <= n; j++) {
            char c;
            cin >> c;

            idx_chr[{-j, i + j}] = c;
        }
    }

    while (m--) {
        string s;
        cin >> s;

        pair<int, int> idx;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') {
                continue;
            }

            if (idx.first == 0) {
                if (s[i] == '\\') {
                    idx.first = -(i + 1);
                } else if (s[i] == '/') {
                    idx.first = i + 1;
                }
            } else {
                if (s[i] == '\\') {
                    idx.second = -(i + 1);
                } else if (s[i] == '/') {
                    idx.second = i + 1;
                }
            }
        }

        cout << idx_chr[idx];
    }
    cout << endl;

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