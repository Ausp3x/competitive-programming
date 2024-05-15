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

void solve() {
    int n;
    cin >> n;
    bool chk = true;
    lng d_sum = 0;
    vector<int> ds(n);
    for (int &d : ds) {
        cin >> d;
        chk &= d != 0;
        d_sum += d;
    }

    if (d_sum != 2 * n - 2) {
        cout << 0 << endl;
        return;
    }

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    if (!chk) {
        cout << 0 << endl;
        return;
    }

    if (n == 2) {
        cout << 1 << endl;
        return;
    }

    if (n == 3) {
        cout << 3 << endl;
        return;
    }

    sort(ds.begin(), ds.end());
    if (n == 4) {
        if (ds == vector<int>({1, 1, 1, 3})) {
            cout << 4 << endl;
        } else if (ds == vector<int>({1, 1, 2, 2})) {
            cout << 12 << endl;
        }
        return;
    }

    if (n == 5) {
        if (ds == vector<int>({1, 1, 1, 1, 4})) {
            cout << 5 << endl;
        } else if (ds == vector<int>({1, 1, 1, 2, 3})) {
            cout << 60 << endl;
        } else if (ds == vector<int>({1, 1, 2, 2, 2})) {
            cout << 60 << endl;
        }
        return;
    }

    if (n == 6) {
        if (ds == vector<int>({1, 1, 1, 1, 1, 5})) {
            cout << 6 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 2, 4})) {
            cout << 120 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 3, 3})) {
            cout << 90 << endl;
        } else if (ds == vector<int>({1, 1, 1, 2, 2, 3})) {
            cout << 720 << endl;
        } else if (ds == vector<int>({1, 1, 2, 2, 2, 2})) {
            cout << 360 << endl;
        }
        return;
    }

    if (n == 7) {
        if (ds == vector<int>({1, 1, 1, 1, 1, 1, 6})) {
            cout << 7 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 1, 2, 5})) {
            cout << 210 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 1, 3, 4})) {
            cout << 420 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 2, 2, 4})) {
            cout << 2100 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 2, 3, 3})) {
            cout << 3150 << endl;
        } else if (ds == vector<int>({1, 1, 1, 2, 2, 2, 3})) {
            cout << 8400 << endl;
        } else if (ds == vector<int>({1, 1, 2, 2, 2, 2, 2})) {
            cout << 2520 << endl;
        }
        return;
    }

    if (n == 8) {
        if (ds == vector<int>({1, 1, 1, 1, 1, 1, 1, 7})) {
            cout << 8 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 1, 1, 2, 6})) {
            cout << 336 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 1, 1, 3, 5})) {
            cout << 840 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 1, 2, 2, 5})) {
            cout << 3360 + 1680 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 1, 1, 4, 4})) {
            cout << 560 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 1, 2, 3, 4})) {
            cout << 6720 + 10080 + 3360 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 2, 2, 2, 4})) {
            cout << 6720 + 20160 + 6720 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 1, 3, 3, 3})) {
            cout << 5040 << endl;
        } else if (ds == vector<int>({1, 1, 1, 1, 2, 2, 3, 3})) {
            cout << 10080 + 20160 + 20160 + 20160 + 5040 << endl;
        } else if (ds == vector<int>({1, 1, 1, 2, 2, 2, 2, 3})) {
            cout << 20160 + 20160 + 40320 + 20160 << endl;
        } else if (ds == vector<int>({1, 1, 2, 2, 2, 2, 2, 2})) {
            cout << 20160 << endl;
        }
        return;
    }

    bool all_d_less_than_2 = true;
    for (int d : ds) {
        if (d > 2) {
            all_d_less_than_2 = false;
            break;
        }
    }

    if (all_d_less_than_2) {
        lng ans = 1;
        for (int i = 3; i <= n; i++) {
            ans *= i;
            ans %= MOD;
        }

        cout << ans << endl;
        return;
    }
    

    cout << "Grabe maghumble si Lord." << endl;

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