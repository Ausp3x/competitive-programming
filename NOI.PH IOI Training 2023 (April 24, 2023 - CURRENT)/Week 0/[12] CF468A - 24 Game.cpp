// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define DEBUG

void solve() {
    int n;
    cin >> n;

    if (n <= 3) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if (n % 2 == 0) {
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
        for (int i = 5; i <= n; i += 2) {
            cout << i + 1 << " - " << i << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
    } else {
        cout << "4 - 2 = 2\n";
        cout << "5 - 1 = 4\n"; 
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n"; 
        for (int i = 6; i <= n; i += 2) {
            cout << i + 1 << " - " << i << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
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
    // cin >> t;
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