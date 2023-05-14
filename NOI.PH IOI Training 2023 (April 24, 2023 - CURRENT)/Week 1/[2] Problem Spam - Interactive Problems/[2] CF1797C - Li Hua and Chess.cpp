// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

#define ONLINE_JUDGE
// #define DEBUG

void solve() {
    int n, m;
    cin >> n >> m;

    lng a;
    cout << "? 1 1" << endl;
    cin >> a;

    lng b = -1;
    if (1 + a <= m) {
        cout << "? 1 " << a + 1 << endl;
        cin >> b;
    }

    lng c = -1;
    if (1 + a <= n) {
        cout << "? " << a + 1 << " 1" << endl;
        cin >> c;
    }

    if (b == -1) {
        cout << "! " << a + 1 << ' ' << c + 1 << endl;
        return;
    }

    if (c == -1) {
        cout << "! " << b + 1 << ' ' << a + 1 << endl;
        return;
    }

    if (b <= c) {
        cout << "! " << b + 1 << ' ' << a + 1 << endl;
    } else {
        cout << "! " << a + 1 << ' ' << c + 1 << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifdef DEBUG
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef DEBUG
    // testing code
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

#ifdef DEBUG
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}