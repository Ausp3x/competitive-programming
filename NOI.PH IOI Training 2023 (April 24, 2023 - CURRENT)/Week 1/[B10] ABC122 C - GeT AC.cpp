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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    vector<int> ac_idxs;
    for (int i = 0; i < n - 1; i++) {
        if (s.substr(i, 2) == "AC") {
            ac_idxs.push_back(i);
        }
    }
    ac_idxs.push_back(1e9); // insert "infinity"

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        
        if (ac_idxs.empty()) {
            cout << 0 << '\n';
            continue;
        }

        int l_idx = lower_bound(ac_idxs.begin(), ac_idxs.end(), l) - ac_idxs.begin(),
            r_idx = lower_bound(ac_idxs.begin(), ac_idxs.end(), r) - ac_idxs.begin();
        
        if (ac_idxs[l_idx] >= r) {
            cout << 0 << '\n';
            continue;
        }

        if (ac_idxs[r_idx] >= r) {
            r_idx--;
        }
        cout << r_idx - l_idx + 1 << '\n';
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