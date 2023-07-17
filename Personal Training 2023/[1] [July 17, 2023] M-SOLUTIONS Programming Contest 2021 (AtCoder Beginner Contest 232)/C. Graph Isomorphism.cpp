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
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, bool> a_b_chks;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a_b_chks[{a - 1, b - 1}] = true;
        a_b_chks[{b - 1, a - 1}] = true;
    }
    vector<pair<int, int>> c_ds(m);
    for (auto &[c, d] : c_ds) {
        cin >> c >> d;
        c--;
        d--;
    }

    vector<int> maps(n);
    for (int i = 0; i < n; i++) {
        maps[i] = i;
    }
    do {
        int cnt = 0;
        for (auto &[c, d] : c_ds) {
            cnt += a_b_chks[{maps[c], maps[d]}];
        }

        if (cnt == m) {
            cout << "Yes" << endl;
            return;
        }

    } while (next_permutation(maps.begin(), maps.end()));

    cout << "No" << endl;

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