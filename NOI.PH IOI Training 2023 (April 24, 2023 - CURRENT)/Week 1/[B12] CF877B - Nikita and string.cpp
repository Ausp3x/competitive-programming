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
    string s;
    cin >> s;

    int n = s.size();
    vector<int> a_cnts(n + 1), b_cnts(n + 1);
    for (int i = 1; i <= n; i++) {
        a_cnts[i] += a_cnts[i - 1] + (s[i - 1] == 'a');
        b_cnts[i] += b_cnts[i - 1] + (s[i - 1] == 'b');
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans = max({ans, a_cnts[i] + b_cnts[j] - b_cnts[i] + a_cnts[n] - a_cnts[j]});
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