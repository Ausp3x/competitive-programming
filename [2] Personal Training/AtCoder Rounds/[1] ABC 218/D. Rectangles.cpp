// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define TROUBLESHOOT

void solve() {
    int n; 
    cin >> n;
    map<pair<int, int>, bool> is_a_point;
    vector<pair<int, int>> points(n);
    for (auto &[x, y] : points) {
        cin >> x >> y;
        is_a_point[{x, y}] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (points[i].first == points[j].first || points[i].second == points[j].second) {
                continue;
            }

            ans += is_a_point[{points[i].first, points[j].second}] && is_a_point[{points[j].first, points[i].second}];
        }
    }
    ans /= 2;

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef TROUBLESHOOT
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef TROUBLESHOOT
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef TROUBLESHOOT
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}