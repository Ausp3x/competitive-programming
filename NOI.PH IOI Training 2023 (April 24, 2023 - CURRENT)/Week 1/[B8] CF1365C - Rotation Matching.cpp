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
    map<int, int> a_idxs;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a_idxs[a] = i;
    }
    map<int, int> distance_cnts;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        distance_cnts[(i - a_idxs[b] + n) % n]++;
    }
    
    int ans = 0;
    for (auto &[k, v] : distance_cnts) {
        ans = max(ans, v);
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