// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define TROUBLESHOOT

void solve() {
    int n;
    cin >> n;

    if (n <= 2) {
        cout << 1 << endl;
        cout << 1 << ' ' << 1 << endl;
        return;
    }

    if (n == 3) {
        cout << 2 << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 3 << ' ' << 3 << endl;
        return;
    }

    if (n == 4) {
        cout << 3 << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 3 << ' ' << 3 << endl;
        cout << 4 << ' ' << 4 << endl;
        return;
    }

    int q = (n - 2) / 3;
    int k = 2 * q + 1 + (n - 2) % 3;
    
    cout << k << endl;
    for (int i = 0; i <= q; i++) {
        cout << 1 + i << ' ' << 1 + q - i << endl;  
    }
    for (int i = 0; i < q; i++) {
        cout << q + 2 + i << ' ' << q + 2 + q - 1 - i << endl;
    }

    if ((n - 2) % 3 == 1) {
        cout << n << ' ' << n << endl;
    } else if ((n - 2) % 3 == 2) {
        cout << n - 1 << ' ' << n - 1 << endl;
        cout << n << ' ' << n << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef TROUBLESHOOT
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef TROUBLESHOOT
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef TROUBLESHOOT
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}