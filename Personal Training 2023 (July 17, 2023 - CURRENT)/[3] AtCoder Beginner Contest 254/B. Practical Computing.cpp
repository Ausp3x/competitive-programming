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

    vector<vector<int>> as(n, vector<int>(n));
    as[0][0] = 1; 
    cout << as[0][0] << endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= i; j++) {
            as[i + 1][j] += as[i][j];
            as[i + 1][j + 1] += as[i][j];
        }

        for (int j = 0; j <= i + 1; j++) {
            cout << as[i + 1][j] << ' ';
        }
        cout << endl;
    }

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