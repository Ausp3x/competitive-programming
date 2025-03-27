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

    if (n <= 3) {
        cout << 0 << endl;
        return;
    }

    // 0 off, 1 on
    int k = sqrt(n);
    vector<bool> states(n + 1);
    while (true) {
        vector<int> idxs;
        for (int i = 1; i <= n - 1 && idxs.size() < k; i++) {
            if (i % k == 0) {
                continue;
            }

            if (states[i] == 0) {
                idxs.push_back(i);
            }
        }

        if (idxs.size() < k) {
            cout << 0 << endl;
            return;
        }

        cout << idxs.size() << ' ';
        for (int x : idxs) {
            cout << x << ' ';
            states[x] = 1;
        }
        cout << endl;

        int res;
        cin >> res;
        for (int i = res; i < res + idxs.size(); i++) {
            states[((i - 1) % n + n) % n + 1] = 0;
        }
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