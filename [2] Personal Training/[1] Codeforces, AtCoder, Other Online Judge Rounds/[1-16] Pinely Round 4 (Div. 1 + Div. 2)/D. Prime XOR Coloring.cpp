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

int N = 200000;
vector<int> primes(N);

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        cout << "1" << endl;
        return;
    }

    if (n == 2) {
        cout << 2 << endl;
        cout << "1 2" << endl;
        return;
    }

    if (n == 3) {
        cout << 2 << endl;
        cout << "1 2 2" << endl;
        return;
    }

    if (n == 4) {
        cout << 3 << endl;
        cout << "1 2 2 3" << endl;
        return;
    }

    if (n == 5) {
        cout << 3 << endl;
        cout << "1 2 2 3 3" << endl;
        return;
    }

    cout << 4 << endl;
    for (int i = 1; i <= n; i++) {
        cout << (i % 4 == 0 ? 4 : i % 4) << ' ';
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