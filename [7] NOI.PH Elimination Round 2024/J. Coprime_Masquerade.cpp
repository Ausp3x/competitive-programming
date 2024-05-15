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

int const MOD = 998244353;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

void solve() {
    int n;
    cin >> n;
    vector<lng> as(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> as[i];
    }

    int prm_len = primes.size();
    vector<int> i_reds(n + 1);
    for (int i = 1; i <= n; i++) {
        int ii = i;
        for (int j = 0; j < prm_len; j++) {
            if (ii % primes[j] != 0) {
                continue;
            }

            i_reds[i] |= 1 << j;
            while (ii % primes[j] == 0) {
                ii /= primes[j];
            }
        }
    }

    // for (int x : i_reds) {
    //     cout << x << ' ';
    // }
    // cout << endl;

    if (n <= 20) {
        lng ans = 0;
        for (int bitmsk = 1; bitmsk < (1 << n); bitmsk++) {
            // for (int i = 0; i < n; i++) {
            //     if (bitmsk & (1 << i)) {
            //         cout << i + 1 << ' ';
            //     }
            // }
            // cout << endl;
            
            int chk = 0;
            lng cur = 1;
            for (int i = 0; i < n; i++) {
                if (!(bitmsk & (1 << i))) {
                    continue;
                }

                if (chk & i_reds[i + 1]) {
                    chk = -1;
                    break;
                }

                chk |= i_reds[i + 1];
                cur *= as[i + 1];
                cur %= MOD;
            }

            if (chk == -1) {
                continue;
            }

            // cout << cur << ' ';
            // cout << endl << endl;

            ans += cur;
            ans %= MOD;
        }

        cout << ans << endl;
        return;
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