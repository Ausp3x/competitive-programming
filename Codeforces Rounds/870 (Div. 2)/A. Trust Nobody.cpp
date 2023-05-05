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
    int n;
    cin >> n;
    map<int, int> l_cnts;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        l_cnts[l]++;
    }
 
    int truthtellers = 0;
    for (auto &[l, cnt] : l_cnts) {
        if (n - truthtellers >= l) {
            truthtellers += cnt;
            if (n - truthtellers < l) {
                cout << -1 << '\n';
                return;
            }
        }
    }
 
    cout << n - truthtellers << '\n';
    
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