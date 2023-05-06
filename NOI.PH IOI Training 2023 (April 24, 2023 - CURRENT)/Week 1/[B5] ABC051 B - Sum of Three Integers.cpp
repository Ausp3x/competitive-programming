// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define ONLINE_JUDGE
// #define DEBUG

void solve() {
    int k, s;
    cin >> k >> s;

    int ans = 0;
    for (int i = k; i >= 0; i--) {
        if (s - i < 0) {
            continue;
        }
        if (s - i > 2 * k) {
            break;
        }
        for (int j = k; j >= 0; j--) {
            if (s - i - j < 0) {
                continue;
            }
            if (s - i - j > k) {
                break;
            }
            ans++;
        }
    }

    cout << ans << '\n';

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