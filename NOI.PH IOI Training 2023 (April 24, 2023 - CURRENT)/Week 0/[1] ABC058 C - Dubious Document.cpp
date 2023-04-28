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
    vector<int> min_ltr_cnts(26, 1e9);
    while (n--) {
        vector<int> ltr_cnts(26);
        string s;
        cin >> s;
        for (char x : s) {
            ltr_cnts[x - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            min_ltr_cnts[i] = min(min_ltr_cnts[i], ltr_cnts[i]);
        }
    }
 
    for (int i = 0; i < 26; i++) {
        cout << string(min_ltr_cnts[i], char('a' + i));
    }
    cout << '\n';
 
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