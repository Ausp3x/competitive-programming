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
    vector<int> as(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> as[i];
    }

    map<int, int> a_maxGaps, a_lastIdxs;
    for (int i = 1; i <= n; i++) {
        a_maxGaps[as[i]] = max(a_maxGaps[as[i]], i - a_lastIdxs[as[i]] - 1);
        a_lastIdxs[as[i]] = i; 
    }
    for (auto &[k, v] : a_maxGaps) {
        v = max(v, n - a_lastIdxs[k]);
    }
    map<int, int> gapMax_aMins;
    for (auto &[k, v] : a_maxGaps) {
        if (gapMax_aMins.contains(v)) {
            gapMax_aMins[v] = min(gapMax_aMins[v], k);
        } else {
            gapMax_aMins[v] = k;
        }
    }
    vector<pair<int, int>> kMin_aMins;
    for (auto &[k, v] : gapMax_aMins) {
        kMin_aMins.push_back({k + 1, v});
    }
    
    int ans = 1e9, j = -1, len = kMin_aMins.size();
    for (int i = 1; i <= n; i++) {
        while (kMin_aMins[j + 1].first <= i && j < len - 1) {
            ans = min(ans, kMin_aMins[j + 1].second);
            j++;
        }
        cout << (ans == 1e9 ? -1 : ans) << ' ';
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