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

int const MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<pair<lng, lng>> V_D(n);
    for (auto &v_d : V_D) {
        cin >> v_d.second;
    }
    for (auto &v_d : V_D) {
        cin >> v_d.first;
    }

    sort(V_D.begin(), V_D.end(), greater<pair<lng, lng>>());

    lng ans = 0;
    for (int i = 0; i < n; i++) {
        (ans += V_D[i].second + i * V_D[i].first) %= MOD; 
    }

    cout << ans << endl;

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