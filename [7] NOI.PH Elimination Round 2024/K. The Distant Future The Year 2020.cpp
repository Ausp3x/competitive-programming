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
    int n, q;
    cin >> n >> q;
    string useless;
    cin.ignore();
    getline(cin, useless);
    vector<int> as(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> as[i];
        as[i] ^= as[i - 1];
    }
    cin.ignore();
    getline(cin, useless);

    lng numer = 0;
    for (int i = 0; i < 31; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (as[j] & (1 << i)) {
                cnt++;
            }
        }

        // cout << i << ' ' << cnt << endl;
        numer += 1ll * cnt * (n - cnt + 1) * (1 << i);
    }

    lng denom = 1ll * n * (n + 1) / 2;
    lng gcd = __gcd(numer, denom);
    cout << numer / gcd << '/' << denom / gcd << endl;

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        
        for (int i = l; i <= r; i += 2) {
            as[i] ^= x;
        }

        if ((l - r + 1) % 2 != 0) {
            for (int i = r + 1; i <= n; i++) {
                as[i] ^= x;
            }
        }

        lng numer = 0;
        for (int i = 0; i < 31; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (as[j] & (1 << i)) {
                    cnt++;
                }
            }

            // cout << i << ' ' << cnt << endl;
            numer += 1ll * cnt * (n - cnt + 1) * (1 << i);
        }

        lng gcd = __gcd(numer, denom);
        cout << numer / gcd << '/' << denom / gcd << endl;
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