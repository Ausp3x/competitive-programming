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
    int n;
    cin >> n;
    vector<int> as(n);
    for (int &a : as) {
        cin >> a;
    }
    string s;
    cin >> s;
    int q;
    cin >> q;

    int ans = 0;
    vector<int> a_xor_prfs(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            ans ^= as[i];
        }

        a_xor_prfs[i + 1] = a_xor_prfs[i] ^ as[i];
    }

    while (q--) {
        int tp;
        cin >> tp;
        
        if (tp == 1) {
            int l, r;
            cin >> l >> r;

            ans ^= a_xor_prfs[r] ^ a_xor_prfs[l - 1];
        } else if (tp == 2) {
            int g;
            cin >> g;

            if (g == 0) {
                cout << ans << ' ';
            } else if (g == 1) {
                cout << (a_xor_prfs[n] ^ ans) << ' ';
            }
        }
    }
    cout << endl;

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