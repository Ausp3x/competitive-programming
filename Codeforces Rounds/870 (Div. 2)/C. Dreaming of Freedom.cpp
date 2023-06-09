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
    int n, m;
    cin >> n >> m;
 
    if (n == 1 || m == 1) {
        cout << "YES\n";
        return;
    }
 
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i <= m || n / i <= m) {
                cout << "NO\n";
                return;
            }
        }
    }
 
    if (n <= m) {
        cout << "NO\n";
        return;
    }
 
    cout << "YES\n";
 
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