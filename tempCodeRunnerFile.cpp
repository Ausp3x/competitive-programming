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
    int n;
    cin >> n;

    map<string, pair<int, int>> compound_idxRanges;
    for (int i = 10; i > 0; i--) {
        vector<int> idxs;
        for (int j = 0; j < n; j++) {
            if (j % (1 << i) < (1 << i - 1)) {
                idxs.push_back(j);
            }
        }

        cout << "MIX" << endl;
        int len = idxs.size();
        cout << len << endl;
        for (int x : idxs) {
            cout << x + 1 << ' ';
        }
        cout << endl;

        map<string, bool> compound_chks;
        for (int j = 1; j <= len; j++) {
            string x;
            cin >> x;            
            
            if (!compound_idxRanges.contains(x)) {
                compound_idxRanges[x] = {0, n - 1};
            }

            compound_chks[x] = true;
            auto [a, b] = compound_idxRanges[x];
            compound_idxRanges[x] = {a, min(a + (1 << i - 1) - 1, b)};
        }

        for (auto &[x, y] : compound_idxRanges) {
            if (compound_chks[x]) {
                continue;
            }
            
            auto [a, b] = y;
            y = {min(a + (1 << i - 1), b), b};
        }

        // cout << "\n/////////////////\n";
        // cout << (1 << i) << '\n';
        // for (auto &[x, y] : compound_idxRanges) {
        //     cout << x << ' ' << y.first << ' ' << y.second << '\n';
        // }
        // cout << "/////////////////\n\n";
    }

    vector<string> ans(n);
    for (auto &[x, y] : compound_idxRanges) {
        ans[y.first] = x;
    }

    cout << "ANSWER" << endl;
    for (auto &x : ans) {
        cout << x << ' ';
    }
    cout << endl;
    
    int rpl;
    cin >> rpl;

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