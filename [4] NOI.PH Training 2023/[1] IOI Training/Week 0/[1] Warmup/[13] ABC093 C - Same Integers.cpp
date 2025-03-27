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
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0, cnt = a % 2 + b % 2 + c % 2; 
    if (cnt == 1) {
        ans++;
        if (a % 2 == 0) {
            a++;
        }
        if (b % 2 == 0) {
            b++;
        }
        if (c % 2 == 0) {
            c++;
        }
    }
    if (cnt == 2) {
        ans++;
        if (a % 2 == 1) {
            a++;
        }
        if (b % 2 == 1) {
            b++;
        }
        if (c % 2 == 1) {
            c++;
        }
    }
    int abc_max = max({a, b, c});
    ans += (abc_max - a) / 2 + (abc_max - b) / 2 + (abc_max - c) / 2;
    
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