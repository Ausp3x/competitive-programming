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
    int n, k;
    cin >> n >> k;
    vector<int> as(n);
    vector<map<int, bool>> a_chks(k);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        a_chks[i % k][as[i]] = true;
    }

    sort(as.begin(), as.end());

    for (int i = 0; i < n; i++) {
        if (!a_chks[i % k][as[i]]) {
            cout << "No" << endl;
            return;
        }
    }
    
    cout << "Yes" << endl;

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