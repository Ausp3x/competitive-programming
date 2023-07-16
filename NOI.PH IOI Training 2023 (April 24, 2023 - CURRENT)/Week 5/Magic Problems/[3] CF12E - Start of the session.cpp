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
    
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 1; i < n; i++) {
        ans[i][0] = ans[i - 1][0] + 1;
        ans[0][i] = ans[i][0];
    }
    for (int i = 2; i < n - 1; i++) {
        for (int j = 1; j < i; j++) {
            ans[i][j] = ans[i][j - 1] + 1;
            if (ans[i][j] > n - 1) {
                ans[i][j] -= n - 1;
            }
            ans[j][i] = ans[i][j];
        }
    }
    for (int j = 1; j < n - 1; j++) {
        ans[n - 1][j] = ans[n - 1][j - 1] + 2;
        if (ans[n - 1][j] > n - 1) {
            ans[n - 1][j] -= n - 1;
        }
        ans[j][n - 1] = ans[n - 1][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
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